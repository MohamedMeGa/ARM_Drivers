/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : EXTI DRIVER                     	*/
/**   		DATE        : 13 DEC 2021                   	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"

/************************************************************/
/**			EXTI Directives						 			*/
/************************************************************/
#include	"EXTI_interface.h"
#include	"EXTI_config.h"
#include	"EXTI_private.h"


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function for Initialize Ext Interrupt 	*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	 
void	EXTI_VoidInit()
{
	#if	EXTI_MODE	==	RISING
		SET_BIT(EXTI ->	RTSR, EXTI_LINE);
	#elif	EXTI_MODE	==	FALLING
		SET_BIT(EXTI ->	FTSR, EXTI_LINE);
	#elif	EXTI_MODE	==	ON_CHANGE
		SET_BIT(EXTI ->	RTSR, EXTI_LINE);
		SET_BIT(EXTI ->	FTSR, EXTI_LINE);
	#else
		#error	"Wrong Mode or Wrong Wrong Line"
	#endif
}



/************************************************************/
/* Description :  function to Enable External Interrupt 	*/
/*				  input	 :	u8 copy_u8EXTILine				*/
/*				  output :	void							*/
/************************************************************/
void	EXTI_VoidEnableEXTI(u8 copy_u8EXTILine)
{
	SET_BIT(EXTI ->	IMR, copy_u8EXTILine);
}


/************************************************************/
/* Description :  function to Disable External Interrupt	*/
/*				  input	 :	u8 copy_u8EXTILine				*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidDisableEXTI(u8 copy_u8EXTILine)
{
	CLEAR_BIT(EXTI ->	IMR, copy_u8EXTILine);
}



/************************************************************/
/* Description :  function for Set Pending Flag 			*/
/*				this flag cleared after clearing 			*/
/*				pending flag								*/
/*				  input	 :	u8 copy_u8EXTILine				*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidSWTrigger(u8 copy_u8EXTILine)
{
	SET_BIT(EXTI ->	SWIER, copy_u8EXTILine);
}





/************************************************************/
/* Description :  function to change the Mode of 			*/
/*					selected line 							*/
/*				  input	 :	u8 copy_u8EXTILine,				*/
/*							u8 copy_u8Mode					*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case RISING 	:	SET_BIT(EXTI ->	RTSR, copy_u8EXTILine);	break;
		case FALLING	:	SET_BIT(EXTI ->	FTSR, copy_u8EXTILine);	break;
		case ON_CHANGE	:	SET_BIT(EXTI ->	RTSR, copy_u8EXTILine);	
							SET_BIT(EXTI ->	FTSR, copy_u8EXTILine);	break;
	}
}


void	EXTI_VoidSetCallBack(void (*ptr)(void))
{
	EXTI0_CallBack = ptr;
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/**				Clear Pending Flag 						*/
	SET_BIT(EXTI->PR, 0);
}