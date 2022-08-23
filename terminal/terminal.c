/*
 * terminal.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Eslam Mohamed
 */


#include"terminal.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
	printf("please,Enter the transaction date as DD/MM/YYYY, e.g 28/03/2022: ");
	fflush(stdin); fflush(stdout);
	gets((char *)termData->transactionDate);

	if(strlen((char *)termData->transactionDate)!=10)
		return WRONG_DATE;

	return TERMINAL_OK;
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	int mon_exp,year_exp,mon_trans,year_trans;

	//get month and year of transaction        21/07/2022
	mon_trans = termData.transactionDate[3] + termData.transactionDate[4]*10;
	year_trans = termData.transactionDate[8] + termData.transactionDate[9]*10;

	//get month and year of expiry       04/26
	mon_exp=cardData.cardExpirationDate[0]+(cardData.cardExpirationDate[1])*10;
	year_exp=cardData.cardExpirationDate[3]+(cardData.cardExpirationDate[4])*10;

	if((year_trans>year_exp)||((year_trans==year_exp)&&(mon_trans>=mon_exp)))
		return CARD_IS_EXPIRED;

	return TERMINAL_OK;
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
	printf("please,Enter the transaction amount: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&termData->transAmount);

	if(termData->transAmount<=0)
		return INVALID_IS_AMOUNT;

	return TERMINAL_OK;
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
	if(termData->transAmount > termData->maxTransAmount)
		return EXCEEDED_MAX_AMOUNT;

	return TERMINAL_OK;
}


EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
	printf("please,Enter the max amount: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&termData->maxTransAmount);

	if(termData->maxTransAmount <=0)
		return INVALID_MAX_AMOUNT;

	return TERMINAL_OK;
}
