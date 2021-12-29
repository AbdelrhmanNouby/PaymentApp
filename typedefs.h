/*************************************
 * Task	  : PaymentAppSystem
 * Created: 12/29/2021 12:54:11 AM
 * Author : Abdelrhman Elsawy
 *************************************/

#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;
typedef char sint8_t;
typedef short int sint16_t;
typedef int sint32_t;
typedef float f32_t;
typedef double f64_t;
typedef long double f128_t;

// struct to hold crad data
typedef struct ST_cardData_t{
	uint8_t cardHolderName[25] ;          // the name written on the card 
	uint8_t primaryAccountNumber[20] ;	  // primary account number written on the card 
	uint8_t cardExpirationDate[6] ;		  // card expiration dte written on the card ( xx/xx )
}ST_cardData_t ;

// struct to hold terminal data 
typedef struct ST_terminalData_t{
	f32_t transAmount ;					// the amount entered by the user
	f32_t maxTransAmount ;				// the max amount can withdrawal once 
	uint8_t transactionDate[11] ;		// the transaction date  
}ST_terminalData_t ;

// stuct to hold account data 
typedef struct ST_accountBalance_t
{
	f32_t balance ; 		              // the balance in the account 
	uint8_t primaryAccountNumber[20] ;	  // PAN of account 
}ST_accountBalance_t ;

// enum to describe transaction statu 
typedef enum EN_transStat_t
{
	DECLINED = -1 ,			// transaction declined 
	APPROVED    			// transaction approved
}EN_transStat_t ;

// struct to hold all transaction data
typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData ;      // all card data for transaction 
	ST_terminalData_t transData ;		// all terminal data for transaction
	EN_transStat_t transStat ;			// tansaction statu 
}ST_transaction_t ;

#endif /*typedefs.h*/
