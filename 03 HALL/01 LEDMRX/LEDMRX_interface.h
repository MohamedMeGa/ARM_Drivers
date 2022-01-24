/************************************************************/
/* 			AUTHOR      : Mohamed MeGa	                  	*/
/* 			DISCRIPTION : LEDMRX DRIVER                     */
/* 			DATE        : 19 DEC 2021                       */
/* 			VERSION     : V01                               */
/************************************************************/

#ifndef	LEDMRX_INT_H
#define	LEDMRX_INT_H

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_TYPES.h"
#include	"Bit_Math.h"

#include	"GPIO_interface.h"
#include	"STK_interface.h"


/************************************************************/
/**			STK Directives						 			*/
/************************************************************/
#include	"LEDMRX_interface.h"
#include	"LEDMRX_config.h"
#include	"LEDMRX_private.h"

void	LEDMRX_VoidInt(void);

void	LEDMRX_VoidDisplay(u8 * copy_u8Data);

#endif