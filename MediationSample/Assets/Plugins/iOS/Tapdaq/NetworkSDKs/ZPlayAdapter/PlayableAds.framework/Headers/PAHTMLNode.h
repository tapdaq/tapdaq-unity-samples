//
//  PAHTMLNode.h
//  StackOverflow
//
//  Created by Ben Reeves on 09/03/2010.
//  Copyright 2010 Ben Reeves. All rights reserved.
//

#import "PAHTMLParser.h"
#import <Foundation/Foundation.h>
#import <libxml/HTMLparser.h>

@class PAHTMLParser;

#define ParsingDepthUnlimited 0
#define ParsingDepthSame -1
#define ParsingDepth size_t

typedef enum {
    PAHTMLHrefNode,
    PAHTMLTextNode,
    PAHTMLUnkownNode,
    PAHTMLCodeNode,
    PAHTMLSpanNode,
    PAHTMLPNode,
    PAHTMLLiNode,
    PAHTMLUlNode,
    PAHTMLImageNode,
    PAHTMLOlNode,
    PAHTMLStrongNode,
    PAHTMLPreNode,
    PAHTMLBlockQuoteNode,
} PAHTMLNodeType;

@interface PAHTMLNode : NSObject {
  @public
    xmlNode *_node;
}

// Init with a lib xml node (shouldn't need to be called manually)
// Use [parser doc] to get the root Node
- (id)initWithXMLNode:(xmlNode *)xmlNode;

// Returns a single child of class
- (PAHTMLNode *)findChildOfClass:(NSString *)className;

// Returns all children of class
- (NSArray *)findChildrenOfClass:(NSString *)className;

// Finds a single child with a matching attribute
// set allowPartial to match partial matches
// e.g. <img src="http://www.google.com> [findChildWithAttribute:@"src" matchingName:"google.com" allowPartial:TRUE]
- (PAHTMLNode *)findChildWithAttribute:(NSString *)attribute
                          matchingName:(NSString *)className
                          allowPartial:(BOOL)partial;

// Finds all children with a matching attribute
- (NSArray *)findChildrenWithAttribute:(NSString *)attribute
                          matchingName:(NSString *)className
                          allowPartial:(BOOL)partial;

// Gets the attribute value matching tha name
- (NSString *)getAttributeNamed:(NSString *)name;

- (void)setValue:(NSString *)value forAttribute:(NSString *)name;

// Find childer with the specified tag name
- (NSArray *)findChildTags:(NSString *)tagName;

// Looks for a tag name e.g. "h3"
- (PAHTMLNode *)findChildTag:(NSString *)tagName;

// Returns the first child element
- (PAHTMLNode *)firstChild;

// Returns the plaintext contents of node
- (NSString *)contents;

// Returns the plaintext contents of this node + all children
- (NSString *)allContents;

// Returns the html contents of the node
- (NSString *)rawContents;

// Returns next sibling in tree
- (PAHTMLNode *)nextSibling;

// Returns previous sibling in tree
- (PAHTMLNode *)previousSibling;

// Returns the class name
- (NSString *)className;

// Returns the tag name
- (NSString *)tagName;

// Returns the parent
- (PAHTMLNode *)parent;

// Returns the first level of children
- (NSArray *)children;

// Returns the node type if know
- (PAHTMLNodeType)nodetype;

// C functions for minor performance increase in tight loops
NSString *getAttributeNamed(xmlNode *node, const char *nameStr);
void setAttributeNamed(xmlNode *node, const char *nameStr, const char *value);
PAHTMLNodeType nodeType(xmlNode *node);
NSString *allNodeContents(xmlNode *node);
NSString *rawContentsOfNode(xmlNode *node);

@end
