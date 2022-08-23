/*
 * application.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Eslam Mohamed
 */


#include "application.h"


void appStart(void)
{
	ST_transaction_t transData;
	ST_cardData_t *cardData = &transData.cardHolderData;

	if(getCardHolderName(cardData))
	{
		printf("WRONG NAME");
		return;
	}

	if(getCardExpiryDate(cardData))
	{
		printf("WRONG EXPIRATION DATE");
		return;
	}
	if(getCardPAN(cardData))
	{
		printf("WRONG PAN");
		return;
	}


	ST_terminalData_t *termData = &transData.terminalData;


	if(getTransactionDate(termData))
	{
		printf("WRONG DATE");
		return;
	}

	if(isCardExpired(*cardData,*termData))
	{
		printf("EXPIRED CARD");
		return;
	}



	if(getTransactionAmount(termData))
	{
		printf("INVALID AMOUNT");
		return;
	}


	if(setMaxAmount(termData))
	{
		printf("INVALID MAXIMUM AMOUNT");
		return;
	}

	if(isBelowMaxAmount(termData))
	{
		printf("EXCEED MAXIMUM AMOUNT");
		return;
	}



	switch(recieveTransactionData(&transData))
	{
	case DECLINED_STOLEN_CARD:
		printf("DECLINED STOLEN CARD");
		break;

	case DECLINED_INSUFFECIENT_FUND:
		printf("DECLINED INSUFFECIENT FUND");
		break;

	case INTERNAL_SERVER_ERROR:
		printf("INTERNAL SERVER ERROR");
		break;

	case APPROVED:
		printf("transaction is APPROVED");
		break;
	}
}
