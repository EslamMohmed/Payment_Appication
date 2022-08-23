/*
 * terminal.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Eslam Mohamed
 */
#include <stdio.h>
#include <time.h>
#include "../card/card.h"
#ifndef TERMINAL_TERMINAL_H_
#define TERMINAL_TERMINAL_H_


typedef struct ST_terminalData_t
{
float transAmount;
float maxTransAmount;
uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
TERMINAL_OK, WRONG_DATE, CARD_IS_EXPIRED, INVALID_IS_CARD, INVALID_IS_AMOUNT, EXCEEDED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);

#endif /* TERMINAL_TERMINAL_H_ */
