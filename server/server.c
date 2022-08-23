/*
 * server.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Eslam Mohamed
 */

#include"server.h"
ST_accountsDB_t arr_acounts[255]={
		{3000.00,"777777777777777777"},
		{6000.00,"888888888888888888"},
		{5000.00,"999999999999999999"},
		{6500.00,"111111111111111111"},
		{7000.00,"222222222222222222"},
		{8000.00,"333333333333333333"},
		{4000.00,"4444444444444444444"},
		{2000.00,"5555555555555555555"},
		{5400.12,"6666666666666666666"},
		{0000.55,"7878787878787878787"}
};

ST_transaction_t arr_transaction[255]={0};
int l,indx;


EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	if(isValidAccount(&transData->cardHolderData))
	{
		arr_transaction[indx].transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}

	else if(isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
	{
		arr_transaction[indx].transState = DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}

	else if(saveTransaction(transData) == FAILED_SAVING)
	{
		arr_transaction[indx].transState = INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;
	}

	else
	{
		arr_transaction[indx].transState = APPROVED;
		arr_acounts[l].balance -= transData->terminalData.transAmount;
		printf("the new balance = %.2f\n",arr_acounts[l].balance);
		return APPROVED;
	}
}


EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
	int flag=0;
	for(l=0;l<255;l++)
	{
		if(strcmp((char *)cardData->primaryAccountNumber,(char *)arr_acounts[l].primaryAccountNumber)==0)
		{
			flag=1;
			break;
		}
	}

	if(flag)
		return SERVER_OK;

	return NOT_ACCOUNT_FOUND;
}


EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{
	if(termData->transAmount > arr_acounts[l].balance)
		return LOW_BALANCE;

	return SERVER_OK;
}


EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	if(indx>=255)
		return FAILED_SAVING;

	arr_transaction[indx]=*transData;
	arr_transaction[indx].transactionSequenceNumber = indx;
	arr_transaction[indx].transState = APPROVED;
	indx++;
	return SERVER_OK;
}


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
{
	for(int i=0;i<255;i++)
	{
		if(transactionSequenceNumber == arr_transaction[i].transactionSequenceNumber)
		{
			*transData=arr_transaction[i];
			return SERVER_OK;
		}
	}
	return NOT_TRANSACTION_FOUND;
}
