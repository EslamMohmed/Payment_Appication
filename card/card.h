/*
 * card.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Eslam Mohamed
 */
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#ifndef CARD_CARD_H_
#define CARD_CARD_H_
typedef unsigned char uint8_t;
typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirationDate[6];
}ST_cardData_t;
typedef enum EN_cardError_t
{
CARD_OK,
NAME_IS_WRONG,
WRONG_EXPIRATION_DATE,
WRONG_PAN
}EN_cardError_t;
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
#endif /* CARD_CARD_H_ */
