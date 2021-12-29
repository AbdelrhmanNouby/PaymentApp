/*************************************
 * Task	  : PaymentAppSystem
 * Created: 12/29/2021 12:54:11 AM
 * Author : Abdelrhman Elsawy
 *************************************/

#ifndef __APIS_H__
#define __APIS_H__

sint8_t getAccount (uint8_t * PAN_arr );
sint8_t ch_amount_ch_balance ( f32_t amount , uint8_t database_index );
sint8_t ch_date ( uint8_t * transaction , uint8_t * expirition );

#endif /*APIs.h*/ 
