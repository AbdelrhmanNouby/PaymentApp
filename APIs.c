 /*************************************
 * Task	  : PaymentAppSystem
 * Created: 12/29/2021 12:54:11 AM
 * Author : Abdelrhman Elsawy
 *************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "typedefs.h"
#include "APIs.h"

// database in server 
ST_accountBalance_t g_server_data[10] = {
	{ 100.0 , "123456789" },
	{ 6000.0 , "234567891" },
	{ 3250.25 , "567891234" },
	{ 1500.12 , "456789123" },
	{ 500.0 , "258649173" },
	{ 2100.0 , "654823719" },
	{ 0.0 , "971362485" },
	{ 1.0 , "793148625"  },
	{ 10.12 , "123123456" },
	{ 0.55 , "456789321" }
};

/******************************************
 function take account number and return 
 its index in database if it found 
 if not found return DECLINED
 ******************************************/
 
sint8_t getAccount(uint8_t * PAN_arr )
{
	uint8_t u8_index;
	for ( u8_index = 0 ; u8_index < 10 ; u8_index++ )
	{
		if ((*(PAN_arr) == *( g_server_data[u8_index].primaryAccountNumber))&&
		(*(PAN_arr+1) == *( g_server_data[u8_index].primaryAccountNumber+1))&&
		(*(PAN_arr+2) == *( g_server_data[u8_index].primaryAccountNumber+2))&&
		(*(PAN_arr+3) == *( g_server_data[u8_index].primaryAccountNumber+3))&&
		(*(PAN_arr+4) == *( g_server_data[u8_index].primaryAccountNumber+4))&&
		(*(PAN_arr+5) == *( g_server_data[u8_index].primaryAccountNumber+5))&&
		(*(PAN_arr+6) == *( g_server_data[u8_index].primaryAccountNumber+6))&&
		(*(PAN_arr+7) == *( g_server_data[u8_index].primaryAccountNumber+7))&&
		(*(PAN_arr+8) == *( g_server_data[u8_index].primaryAccountNumber+8)))
		{
				return 	u8_index ;
		}
	} 
	return DECLINED ; // account not found 
}

/***********************************************************
 function to take amount and index of account in database 
 to check if amount less than the balance and max transaction value 
 if yes update the balance and return APPROVED if not return DECLINED
 ***********************************************************/

sint8_t ch_amount_ch_balance ( f32_t amount , uint8_t database_index )
{
	if (( amount > 5000 ) || ( amount > g_server_data[database_index].balance ))
		return DECLINED ;
	else
	{
		g_server_data[database_index].balance -= amount ;
		return APPROVED ;	
	}
}

/**********************************************************
function to check if the transaction date before expirition date  
if yes return APPROVED if not return DECLINED 
*********************************************************/

sint8_t ch_date ( uint8_t * transaction , uint8_t * expirition )
{		
	const uint8_t dlim[2] = "/";
    uint8_t * trans_year ;
    uint8_t * trans_month ;
    uint8_t * trans_day;
    uint8_t * expir_year ;
    uint8_t * expir_month ;    
    expir_month = (uint8_t*)strtok( expirition , dlim );		// extract year and month of expirition 
    expir_year = (uint8_t*)strtok( NULL ,dlim );
    uint8_t u8_expir_month = (uint8_t)atoi(expir_month);
    uint16_t u16_expir_year = (uint16_t)(atoi(expir_year)) + 2000 ;
    
    trans_day = (uint8_t*)strtok( transaction , dlim );        // extract year and month of transaction
    trans_month= (uint8_t*)strtok( NULL ,dlim );
    uint8_t u8_trans_month = (uint8_t)atoi(trans_month);
    trans_year= (uint8_t*)strtok( NULL ,dlim );
    uint16_t u16_trans_year = (uint16_t)atoi(trans_year) ;
    
    if ( u16_trans_year > u16_expir_year )				
    	return DECLINED ;
     else if (( u16_trans_year == u16_expir_year )&&( u8_trans_month > u8_expir_month ))
    	return DECLINED ;
    else 
    	return APPROVED ;
}
