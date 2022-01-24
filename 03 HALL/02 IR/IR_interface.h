/************************************************************/
/* 			AUTHOR      : Mohamed MeGa	                  	*/
/* 			DISCRIPTION : IR DRIVER                   	  	*/
/* 			DATE        : 21 DEC 2021                       */
/* 			VERSION     : V01                               */
/************************************************************/

#ifndef	IR_INT_H
#define	IR_INT_H

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_TYPES.h"
#include	"Bit_Math.h"

#include	"GPIO_interface.h"
#include	"STK_interface.h"


/************************************************************/
/**			IR Directives						 			*/
/************************************************************/
#include	"IR_interface.h"
#include	"IR_config.h"
#include	"IR_private.h"

void	IR_VoidInit(void);



void	IR_VoidGetFrame(void);




#endif