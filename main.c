/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Eslam Mohamed
 */

#include"stdio.h"
#include "./Application/application.h"
int main()
{
	uint8_t ex = 0;
	        while (ex != 'X' && ex != 'x')
	        {
	            appStart();
	            printf("\npleae Enter X to close the program or any char to continue: ");
	            scanf(" %c", &ex);
	        }
	return 0;
}
