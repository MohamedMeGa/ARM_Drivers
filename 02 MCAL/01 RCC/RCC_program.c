/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : RCC DRIVER                     	*/
/**   		DATE        : 05 DEC 2021                   	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"

/************************************************************/
/**			DIO Directives						 			*/
/************************************************************/
#include	"RCC_interface.h"
#include	"RCC_config.h"
#include	"RCC_private.h"


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function for initialization The RCC		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	 
void	RCC_VoidInitSystemClock(void)
{
	#if		RCC_CLOCK_TYPE	==	RCC_HSI
		RCC_CR		=	0x00000081;	
		RCC_CFGR	=	0x00000000;
	#elif	RCC_CLOCK_TYPE	==	RCC_HSE_CRYSTAL
		RCC_CR		=	0x00010000;		//	Enable HSE with no ByBass
		RCC_CFGR	=	0x00000001;
	#elif	RCC_CLOCK_TYPE	==	RCC_HSE_RC
		RCC_CR		=	0x00050000;		//	Enable HSE with ByBass
		RCC_CFGR	=	0x00000001;
	#elif	RCC_CLOCK_TYPE	==	RCC_PLL
	
		#if		RCC_PLL_SOURCE_TYPE	==	PLL_HSI_DIVBY_2
			RCC_CR		=	0x01000000;
			RCC_CFGR	=	0x00000002;
		#elif	RCC_PLL_SOURCE_TYPE	==	PLL_HSE
			RCC_CR		=	0x01000081;
			RCC_CFGR	=	0x00030002;
		#elif	RCC_PLL_SOURCE_TYPE	==	PLL_HSE_DIVBY_2
			RCC_CR		=	0x01000081;
			RCC_CFGR	=	0x00010002;
		#else
			#error ("you choosed wrong vlock type")
		#endif
		
	#endif
}



/************************************************************/
/* Description :  function for Enable Clock 				*/
/*				  input	 :	u8	copy_u8BusID,				*/
/*							u8	copy_u8PeriherialID			*/
/*				  output :	void							*/
/************************************************************/	
void	RCC_VoidEnableClock(u8	copy_u8BusID, u8	copy_u8PeriherialID)
{
	if(copy_u8PeriherialID <= 31)
	{
		switch	(copy_u8BusID)
		{
			case	RCC_AHB:
				SET_BIT(RCC_AHBENR, copy_u8PeriherialID);
				break;
			case	RCC_ABP1 :
				SET_BIT(RCC_ABP2ENR, copy_u8PeriherialID);
				break;
			case	RCC_ABP2 :
				SET_BIT(RCC_ABP2ENR, copy_u8PeriherialID);
				break;
		}
	}
	else{
		//Not Found
	}
}


/************************************************************/
/* Description :  function for Enable Clock 				*/
/*				  input	 :	u8	copy_u8BusID,				*/
/*							u8	copy_u8PeriherialID			*/
/*				  output :	void							*/
/************************************************************/	
void	RCC_VoidDisableClock(u8	copy_u8BusID, u8	copy_u8PeriherialID)
{
	if(copy_u8PeriherialID <= 31)
	{
		switch	(copy_u8BusID)
		{
			case	RCC_AHB:
				CLEAR_BIT(RCC_AHBENR, copy_u8PeriherialID);
				break;
			case	RCC_ABP1 :
				CLEAR_BIT(RCC_ABP2ENR, copy_u8PeriherialID);
				break;
			case	RCC_ABP2 :
				CLEAR_BIT(RCC_ABP2ENR, copy_u8PeriherialID);
				break;
		}
	}
	else{
		//Not Found
	}
}