//
//  PSTCKCardParams.h
//  Paystack
//

#import <Foundation/Foundation.h>
#import "PSTCKFormEncodable.h"
/**
 *  Representation of a user's credit card details. You can assemble these with information that your user enters and
 *  then create Paystack tokens with them using an PSTCKAPIClient. @see https://paystack.com/docs/api#cards
 */
@interface PSTCKCardParams : NSObject<PSTCKFormEncodable>

/**
 *  The card's number.
 */
@property (nonatomic, copy, nullable) NSString *number;

/**
 *  The last 4 digits of the card's number, if it's been set, otherwise nil.
 */
- (nullable NSString *)last4;

/**
 *  The clientdata to send to api.
 */
- (nullable NSString *)clientdata;

/**
 *  The card's expiration month.
 */
@property (nonatomic) NSUInteger expMonth;

/**
 *  The card's expiration year.
 */
@property (nonatomic) NSUInteger expYear;

/**
 *  The card's security code, found on the back.
 */
@property (nonatomic, copy, nullable) NSString *cvc;

/**
 *  The cardholder's name.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 *  The cardholder's address.
 */
@property (nonatomic, copy, nullable) NSString *addressLine1;
@property (nonatomic, copy, nullable) NSString *addressLine2;
@property (nonatomic, copy, nullable) NSString *addressCity;
@property (nonatomic, copy, nullable) NSString *addressState;
@property (nonatomic, copy, nullable) NSString *addressZip;
@property (nonatomic, copy, nullable) NSString *addressCountry;

/**
 *  Three-letter ISO currency code representing the currency paid out to the bank account. This is only applicable when tokenizing debit cards to issue payouts to managed accounts. You should not set it otherwise. The card can then be used as a transfer destination for funds in this currency.
 */
@property (nonatomic, copy, nullable) NSString *currency;

/**
 *  Validate each field of the card.
 *  @return whether or not that field is valid.
 *  @deprecated use PSTCKCardValidator instead.
 */
- (BOOL)validateNumber:(__nullable id * __nullable )ioValue
                 error:(NSError * __nullable * __nullable )outError __attribute__((deprecated("Use PSTCKCardValidator instead.")));
- (BOOL)validateCvc:(__nullable id * __nullable )ioValue
              error:(NSError * __nullable * __nullable )outError __attribute__((deprecated("Use PSTCKCardValidator instead.")));
- (BOOL)validateExpMonth:(__nullable  id * __nullable )ioValue
                   error:(NSError * __nullable * __nullable )outError __attribute__((deprecated("Use PSTCKCardValidator instead.")));
- (BOOL)validateExpYear:(__nullable id * __nullable)ioValue
                  error:(NSError * __nullable * __nullable )outError __attribute__((deprecated("Use PSTCKCardValidator instead.")));

/**
 *  This validates a fully populated card to check for all errors, including ones that come about
 *  from the interaction of more than one property. It will also do all the validations on individual
 *  properties, so if you only want to call one method on your card to validate it after setting all the
 *  properties, call this one
 *
 *  @param outError a pointer to an NSError that, after calling this method, will be populated with an error if the card is not valid. See PaystackError.h for
 possible values
 *
 *  @return whether or not the card is valid.
 *  @deprecated use PSTCKCardValidator instead.
 */
- (BOOL)validateCardReturningError:(NSError * __nullable * __nullable)outError __attribute__((deprecated("Use PSTCKCardValidator instead.")));

@end
