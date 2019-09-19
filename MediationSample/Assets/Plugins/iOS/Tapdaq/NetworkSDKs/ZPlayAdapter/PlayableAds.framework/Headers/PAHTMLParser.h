//
//  PAHTMLParser.h
//  StackOverflow
//
//  Created by Ben Reeves on 09/03/2010.
//  Copyright 2010 Ben Reeves. All rights reserved.
//

#import "PAHTMLNode.h"
#import <Foundation/Foundation.h>
#import <libxml/HTMLparser.h>

@class PAHTMLNode;

@interface PAHTMLParser : NSObject {
  @public
    htmlDocPtr _doc;
}

- (id)initWithContentsOfURL:(NSURL *)url error:(NSError **)error;
- (id)initWithData:(NSData *)data error:(NSError **)error;
- (id)initWithString:(NSString *)string error:(NSError **)error;

// Returns the doc tag
- (PAHTMLNode *)doc;

// Returns the body tag
- (PAHTMLNode *)body;

// Returns the html tag
- (PAHTMLNode *)html;

// Returns the head tag
- (PAHTMLNode *)head;

@end
