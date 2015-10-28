//
//  NSStringAdditions.h
//  
//
//  Created by luobin on 12-3-8.
//  Copyright 2011 ZhangShangTong Stock Co., Ltd. All rights reserved.

#import <Foundation/Foundation.h>

@interface NSString (TKCategory)

- (BOOL)isAlpha;

- (BOOL)isNumber;

- (BOOL)isWhitespace;

- (BOOL)isEmptyOrWhitespace;

- (NSString *)stringByTrimmingWhitespaceCharacters;

- (NSString *)stringByTrimmingTrailingCharactersInSet:(NSCharacterSet *)characterSet;

- (NSString *)stringByTrimmingTrailingWhitespaceAndNewlineCharacters;

- (NSString*)stringByRemovingHTMLTags;

+ (NSString *)stringByTrimmingWhitespaceCharactersAndAngleBracket:(NSString *)string;


///-----------------------------------
/// @name HTML Escaping and Unescaping
///-----------------------------------

/**
 Returns a new string with any HTML escaped.
 
 @return A new string with any HTML escaped.
 
 @see unescapeHTML
 */
- (NSString *)escapeHTML;

/**
 Returns a new string with any HTML unescaped.
 
 @return A new string with any HTML unescaped.
 
 @see escapeHTML
 */
- (NSString *)unescapeHTML;

@end

@interface NSString (version)

- (NSComparisonResult)versionStringCompare:(NSString *)other;

@end

@interface NSString (NSURL)

extern NSString * const stringLogQuery(NSDictionary *query);

extern NSString * const stringLogValue(NSString *str);

- (NSDictionary*)queryDictionaryUsingEncoding:(NSStringEncoding)encoding;

+ (NSString *)stringASCQuery:(NSDictionary*)query;

- (NSString*)stringByAddingQuery:(NSDictionary*)query;

- (NSString*)urlEncodeValue;

- (NSString*)urlDecodeValue;

@end

@interface NSString (UUID)

+ (NSString*)stringWithNewUUID;

@end


@interface NSString (md5)

extern NSString * const stringLog(NSString *str);
- (NSString *) md5;
@end

#import "NSDataAdditions.h"

@interface NSString (DESEncryptExtention)

- (NSString*)desEncryptWithKey:(NSString*)key;
- (NSString*)desDecryptWithKey:(NSString*)key;

@end