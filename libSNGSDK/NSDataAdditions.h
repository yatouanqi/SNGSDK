//
//  NSDataAdditions.h
//  TKCommonLib
//
//  Created by luobin on 11-7-12.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>


@interface NSData (Base64)
+ (id)dataWithBase64EncodedString:(NSString *)string;     //  Padding '=' characters are optional. Whitespace is ignored.
- (NSString *)base64Encoding;

@end

@interface NSData (MD5)
- (NSString *) MD5;
@end

@interface NSData (SHA1)
- (NSString *) SHA1;
@end
