# Merge Script

# 1
# Set bash script to exit immediately if any commands fail.
set -e

# 2
# Setup some constants for use later on.
# FRAMEWORK_NAME="YouAppi"
# CONFIGURATION="Production"

# 3
# If remnants from a previous build exist, delete them.
if [ -d "${SRCROOT}/build" ]; then
rm -rf "${SRCROOT}/build"
fi

# 4
# Build the framework for device and for simulator (using
# all needed architectures).
echo "Building for Device.."
xcodebuild -target "${FRAMEWORK_NAME}" -configuration "${CONFIGURATION}" -arch arm64 -arch armv7 only_active_arch=no defines_module=yes -sdk "iphoneos" ENABLE_BITCODE=YES OTHER_CFLAGS="-fembed-bitcode" BITCODE_GENERATION_MODE=bitcode

echo "Building for Simulator.."
xcodebuild -target "${FRAMEWORK_NAME}" -configuration "${CONFIGURATION}" -arch x86_64 -arch i386 VALID_ARCHS="i386 x86_64"  only_active_arch=no defines_module=yes -sdk "iphonesimulator" ENABLE_BITCODE=YES OTHER_CFLAGS="-fembed-bitcode" BITCODE_GENERATION_MODE=bitcode

# 5
# Remove .framework file if exists on Desktop from previous run.
if [ -d "${HOME}/Desktop/${FRAMEWORK_NAME}.framework" ]; then
rm -rf "${HOME}/Desktop/${FRAMEWORK_NAME}.framework"
fi

echo "Fixing script file permissions.."
# 5.1
# Fix strip-framework.sh permissions so it can be executed from app scripts phase
chmod +x "${SRCROOT}/build/${CONFIGURATION}-iphoneos/${FRAMEWORK_NAME}.framework/strip-frameworks.sh"
chmod +x "${SRCROOT}/build/${CONFIGURATION}-iphonesimulator/${FRAMEWORK_NAME}.framework/strip-frameworks.sh"

# 6
# Copy the device version of framework to Desktop.
cp -r "${SRCROOT}/build/${CONFIGURATION}-iphoneos/${FRAMEWORK_NAME}.framework" "${HOME}/Desktop/${FRAMEWORK_NAME}.framework"

echo "Merging frameworks.."
# 7
# Replace the framework executable within the framework with
# a new version created by merging the device and simulator
# frameworks' executables with lipo.
lipo -create -output "${HOME}/Desktop/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}" "${SRCROOT}/build/${CONFIGURATION}-iphoneos/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}" "${SRCROOT}/build/${CONFIGURATION}-iphonesimulator/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}"

# 8
# Copy the Swift module mappings for the simulator into the
# framework.  The device mappings already exist from step 6.
cp -r "${SRCROOT}/build/${CONFIGURATION}-iphonesimulator/${FRAMEWORK_NAME}.framework/Modules/${FRAMEWORK_NAME}.swiftmodule/" "${HOME}/Desktop/${FRAMEWORK_NAME}.framework/Modules/${FRAMEWORK_NAME}.swiftmodule"

# 9
# Delete the most recent build.
if [ -d "${SRCROOT}/build" ]; then
rm -rf "${SRCROOT}/build"
fi

open "${HOME}/Desktop/${FRAMEWORK_NAME}.framework/"
