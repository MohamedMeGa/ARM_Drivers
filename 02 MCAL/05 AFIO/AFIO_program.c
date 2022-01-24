/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : AFIO DRIVER                     	*/
/**   		DATE        : 13 DEC 2021                   	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_TYPES.h"
#include	"Bit_Math.h"

/************************************************************/
/**			EXTI Directives						 			*/
/************************************************************/
#include	"AFIO_interface.h"
#include	"AFIO_config.h"
#include	"AFIO_private.h"


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function to Set EXTI Configuration	 	*/
/*				  input	 :	u8 copy_u8Line,					*/
/*							u8 copy_u8RoadMaP				*/
/*				  output :	void							*/
/************************************************************/		 
void	AFIO_VoidSetEXTIConfiguration(u8 copy_u8Line, u8 copy_u8RoadMaP)
{
	u8 Local_u8RegIndex = 0;
	
	if(copy_u8Line <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(copy_u8Line <= 7)
	{
		Local_u8RegIndex = 1;
		copy_u8Line -= 4;
	}
	else if(copy_u8Line <= 11)
	{
		Local_u8RegIndex = 2;
		copy_u8Line -= 8;
	}
	else if(copy_u8Line <= 15)
	{
		Local_u8RegIndex = 3;
		copy_u8Line -= 12;
	}
	else
	{
		#error	"Wrong Selected Value"
	}
	/**	This Line to Reset The REgister						*/
	AFIO -> EXTICR[Local_u8RegIndex] &~= ((0b1111) << (copy_u8Line * 4));
	
	/**	This Line To Set the register to selected Value		*/
	AFIO -> EXTICR[Local_u8RegIndex] |= ((copy_u8RoadMaP) << (copy_u8Line * 4));
}