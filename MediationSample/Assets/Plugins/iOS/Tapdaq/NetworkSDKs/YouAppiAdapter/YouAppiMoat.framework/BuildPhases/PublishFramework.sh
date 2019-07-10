exec > /tmp/${PROJECT_NAME}_archive.log 2>&1
export LANG=en_US.UTF-8

#PODSPEC_FILENAME="YouAppiMoatSDK.podspec"
#FRAMEWORK_NAME="YouAppiMoat"
#CONFIGURATION="Production"

XCODE_DEVELOPER_DIR_PATH="/Applications/Xcode.app/Contents/Developer/"
export XCODE_DEVELOPER_DIR_PATH

echo "<---------------------------------------------------------------------------->"
echo ""
echo "In order for CocoaPods to work you need to make sure you registered with CocoaPods"
echo "1. pod trunk register guy.b@youappi.com 'Guy Bashan'"
echo "2. Verify the email from CocoaPods"
echo "3. do 'pod trunk me' and verify it's properly registered"
echo "4. Tip - you can add other owners and allow them to upload - 'pod trunk add-owner YouAppiMoat_Framework guy.b@youappi.com"
echo "If you get crashes in pod you need to sudo rm ~/.netrc and register again"
echo ""
echo "<---------------------------------------------------------------------------->"
echo ""

open /tmp/${PROJECT_NAME}_archive.log

osascript -e 'display notification "Archiving. Please Wait.." with title "FRAMEWORK"'

UNIVERSAL_OUTPUTFOLDER=${BUILD_DIR}/${CONFIGURATION}-universal

DEVICE_BCSYMBOLMAP_PATH="${BUILD_DIR}/${CONFIGURATION}-iphoneos"
DEVICE_DSYM_PATH="${BUILD_DIR}/${CONFIGURATION}-iphoneos/${FRAMEWORK_NAME}.framework.dSYM"
SIMULATOR_DSYM_PATH="${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/${FRAMEWORK_NAME}.framework.dSYM"
DIST_DIR="${PROJECT_DIR}/Distribution"

if [ "true" == ${ALREADYINVOKED:-false} ]
then
echo "[*] RECURSION: Detected, stopping"
else
export ALREADYINVOKED="true"

# make sure the output directory exists
mkdir -p "${UNIVERSAL_OUTPUTFOLDER}"
mkdir -p "${DIST_DIR}"

echo "[*] Building for iPhoneSimulator"
xcodebuild -workspace "${WORKSPACE_PATH}" -scheme "${TARGET_NAME}" -configuration ${CONFIGURATION} -sdk iphonesimulator -destination 'platform=iOS Simulator,name=iPhone XS Max' ONLY_ACTIVE_ARCH=NO ARCHS='i386 x86_64' BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}" ENABLE_BITCODE=YES OTHER_CFLAGS="-fembed-bitcode" BITCODE_GENERATION_MODE=bitcode clean build

# Step 1. Copy the framework structure (from iphoneos build) to the universal folder
echo "[*] Copying to output folder"
cp -R "${BUILD_DIR}/${CONFIGURATION}-iphoneos/${FULL_PRODUCT_NAME}" "${UNIVERSAL_OUTPUTFOLDER}/"

# Step 2. Copy Swift modules from iphonesimulator build (if it exists) to the copied framework directory
SIMULATOR_SWIFT_MODULES_DIR="${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/."
if [ -d "${SIMULATOR_SWIFT_MODULES_DIR}" ]; then
cp -R "${SIMULATOR_SWIFT_MODULES_DIR}" "${UNIVERSAL_OUTPUTFOLDER}/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule"
fi

# Step 3. Create universal binary file using lipo and place the combined executable in the copied framework directory
echo "[*] Combining executables"
lipo -create -output "${UNIVERSAL_OUTPUTFOLDER}/${EXECUTABLE_PATH}" "${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/${EXECUTABLE_PATH}" "${BUILD_DIR}/${CONFIGURATION}-iphoneos/${EXECUTABLE_PATH}"

# Create universal binaries for embedded frameworks
#for SUB_FRAMEWORK in $( ls "${UNIVERSAL_OUTPUTFOLDER}/${TARGET_NAME}.framework/Frameworks" ); do
#BINARY_NAME="${SUB_FRAMEWORK%.*}"
#lipo -create -output "${UNIVERSAL_OUTPUTFOLDER}/${TARGET_NAME}.framework/Frameworks/${SUB_FRAMEWORK}/${BINARY_NAME}" "${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/${SUB_FRAMEWORK}/${BINARY_NAME}" "${ARCHIVE_PRODUCTS_PATH}${INSTALL_PATH}/${TARGET_NAME}.framework/Frameworks/${SUB_FRAMEWORK}/${BINARY_NAME}"
#done

# Step 4. Convenience step to copy the framework to the project's directory
echo "[*] Copying to project dir (${DIST_DIR})"
rm -Rf "${DIST_DIR}/${FULL_PRODUCT_NAME}" || true
mkdir "${DIST_DIR}/${FULL_PRODUCT_NAME}" || true
cp -pRf "${UNIVERSAL_OUTPUTFOLDER}/${FULL_PRODUCT_NAME}/." "${DIST_DIR}/${FULL_PRODUCT_NAME}/."

# Step 5. Copy and lipo dSYM files
if [ "${CONFIGURATION}" == "Production" ]  || [ "${CONFIGURATION}" == "Release" ]
then
echo "[*] Copying dSYM to project dir"
cp -r "${DEVICE_DSYM_PATH}" "${DIST_DIR}"

lipo -create -output "${DIST_DIR}/${FRAMEWORK_NAME}.framework.dSYM/Contents/Resources/DWARF/${FRAMEWORK_NAME}" "${DEVICE_DSYM_PATH}/Contents/Resources/DWARF/${FRAMEWORK_NAME}" "${SIMULATOR_DSYM_PATH}/Contents/Resources/DWARF/${FRAMEWORK_NAME}" || exit 1

UUIDs=$(dwarfdump --uuid "${DEVICE_DSYM_PATH}" | cut -d ' ' -f2)
for file in `find "${DEVICE_BCSYMBOLMAP_PATH}" -name "*.bcsymbolmap" -type f`; do
fileName=$(basename "$file" ".bcsymbolmap")
for UUID in $UUIDs; do
if [ "$UUID" = "$fileName" ]
then
cp -R "$file" "${DIST_DIR}"
dsymutil --symbol-map "${DIST_DIR}"/"$fileName".bcsymbolmap "${DIST_DIR}/${FRAMEWORK_NAME}.framework.dSYM"
fi
done
done
fi

# Step 7. Extract the version number and update build number 
echo "[*] Extracting version number.."

BUILD_NUMBER=$(/usr/libexec/PlistBuddy -c "Print CFBundleVersion" "${PROJECT_DIR}/${INFOPLIST_FILE}")
SHORT_VERSION=$(/usr/libexec/PlistBuddy -c "Print CFBundleShortVersionString" "${PROJECT_DIR}/${INFOPLIST_FILE}")

BUILD_NUMBER=$(($BUILD_NUMBER + 1))
/usr/libexec/PlistBuddy -c "Set :CFBundleVersion $BUILD_NUMBER" "${PROJECT_DIR}/${INFOPLIST_FILE}"
#echo "[*] ${INFOPLIST_FILE}"
# also update the build number in the final version
/usr/libexec/PlistBuddy -c "Set :CFBundleVersion $BUILD_NUMBER" "${DIST_DIR}/${FULL_PRODUCT_NAME}/Info.plist"

echo "[*] Configuration is ${CONFIGURATION}"
if [ "${CONFIGURATION}" == "Debug" ]; then

VERSION=${SHORT_VERSION}+build.${BUILD_NUMBER}
URL_VERSION=${SHORT_VERSION}%2Bbuild.${BUILD_NUMBER}

elif [ "${CONFIGURATION}" == "Production" ]; then

VERSION=${SHORT_VERSION}
URL_VERSION=${SHORT_VERSION}

fi

# open the folder that contains the framework and dSYM (if exists)
mkdir ${DIST_DIR} || true
cd "${DIST_DIR}"
open "."

# Step 8. Build zip to deploy to cocoapods
echo "[*] Preparing Zip for CocoaPods.."

cp -pfR ${FULL_PRODUCT_NAME}/LICENSE .
ZIP_FILENAME=${PRODUCT_NAME}_${VERSION}.zip
zip -r ${ZIP_FILENAME} ${FULL_PRODUCT_NAME} LICENSE
rm LICENSE

if [ -f "${ZIP_FILENAME}" ]
then

echo "[*] Zip is ready (${ZIP_FILENAME}).."

# Step 9. Upload zip to cocoapods
echo "[*] Uploading to S3.."
osascript -e 'display notification "Uploading to Server.." with title "FRAMEWORK"'

echo "[*] If Upload fails, you must first install the aws cli tools"

#sometimes aws is not located in ~/bin/
AWS_EXEC="aws"
if [[ -f $(bash -c "echo ~/bin/aws") ]]; then
AWS_EXEC=$(bash -c "echo ~/bin/aws")
fi

if [ "${CONFIGURATION}" == "Debug" ]; then

FOLDER="cocoapods-private"

elif [ "${CONFIGURATION}" == "Production" ]; then

FOLDER="cocoapods"

fi

AWS_ACCESS_KEY_ID=AKIAJVJMFAWEDTPZ5LOQ AWS_SECRET_ACCESS_KEY=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 ${AWS_EXEC} s3 cp ./${ZIP_FILENAME} s3://static.youappi.com/sdk/${FOLDER}/ --acl public-read

if [ ! -f "/usr/local/bin/pod" ];
then
echo "[*] CocoaPods not installed."
osascript -e 'display notification "CocoaPods not installed. visit http://cocoapods.org for instructions." with title "FRAMEWORK"'
exit 0
fi

# Step 10. Update cocoapods podspec
echo "[*] Fixing CocoaPods Spec.."

PODSPEC_PATH="/tmp/${PODSPEC_FILENAME}"

#Update the version inside the podspec file

cp -pfR "${PROJECT_DIR}/LICENSE" /tmp/.
cp -pfR "${PROJECT_DIR}/.swift-version" /tmp/.
cp -pfR "${PROJECT_DIR}/${PODSPEC_FILENAME}" ${PODSPEC_PATH}
sed -ie "s/##VERSION##/${VERSION}/g" ${PODSPEC_PATH}
sed -ie "s/##URL_VERSION##/${URL_VERSION}/g" ${PODSPEC_PATH}

# Step 11. Verify pod.
echo "Verifying CocoaPods Spec.."
pod spec lint --no-ansi ${PODSPEC_PATH}

osascript -e 'display notification "Uploading to CocoaPods.." with title "FRAMEWORK"'

# Step 12. Deploy to cocoapods.
echo "[*] Uploading CocoaPods Spec (${PODSPEC_PATH}).."
pod trunk push --allow-warnings ${PODSPEC_PATH}
echo
echo "[*] Done"

osascript -e 'display notification "Done.  CocoaPods-Compliant & Universal Compiled & Uploaded" with title "SUCCESS"'
else
osascript -e 'display notification "Failed to Zip & Upload Framework" with title "FAILED"'
osascript -e 'say "YouAppi Compile & Upload Failed"'

fi
fi

fi
