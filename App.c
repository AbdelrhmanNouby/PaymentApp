/*************************************
 * Task	  : PaymentAppSystem
 * Created: 12/29/2021 12:54:11 AM
 * Author : Abdelrhman Elsawy
 *************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "typedefs.h"
 #include "APIs.h"
 
 extern ST_accountBalance_t g_server_data[10];
 
 main()
 {
	uint8_t moreTransacion = 'y' ;     // checker to make anuther transaction or not 
	ST_cardData_t cardData ; 		   // strauct to hold card data for every transaction 
	ST_terminalData_t terminalData ;   // struct to hold terminal data for every transaction
 	
 	while( moreTransacion == 'y' || moreTransacion == 'Y') 			// if no more transaction end the programe
 	{	
	 	printf("Please Enter Card Data : \n");						
 		printf("Please Enter the Card Holder Name : \n");
		scanf("%[^\n]%*c",&cardData.cardHolderName);
 		printf("Please Enter the Primary Account Number : \n");	
		scanf("%s",&cardData.primaryAccountNumber);	
 		printf("Please Enter the Card Epirition date : \n");
		scanf("%s",&cardData.cardExpirationDate);
	 	printf("Please Enter Terminal Data : \n");
 		printf("Please Enter the Transaction Amount : \n");
		scanf("%s",&terminalData.transAmount);
 		printf("Please Enter the Transaction Date : \n");	
		scanf("%s",&terminalData.transactionDate);				
		printf("Verifying Data From Server ..... \n");	
		
		// check if account found or not
		if( getAccount(cardData.primaryAccountNumber) == DECLINED )				 
        	printf("The Transaction Is DECLINED \n");
 		// check transaction date before epirition date or not 
 	    else if ( ch_date(&terminalData.transactionDate,&cardData.cardExpirationDate) == DECLINED )   
    		printf("The Transaction Is DECLINED \n");
 		// check amount less than max amount in one transaction and less than account balance 
		else if ((ch_amount_ch_balance(atof(&terminalData.transAmount),getAccount(cardData.primaryAccountNumber)) == DECLINED ))
			printf("The Transaction Is DECLINED \n");
		// if all conditions approved will make transaction 
		else
			printf("The Transaction Is APPROVED \n");
		
		printf("Do You Want To Continue(y/n)\n");    // ask if want more transaction or not 
		scanf("%s",&moreTransacion);
		_flushall();								// make sure all buffers is clear 
 	}
 }
 