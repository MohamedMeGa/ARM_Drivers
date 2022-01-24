/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : SysTick DRIVER                    */
/**   		DATE        : 15 DEC 2021                   	*/
/**   		VERSION     : V01                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_TYPES.h"
#include	"Bit_Math.h"

/************************************************************/
/**			STK Directives						 			*/
/************************************************************/
#include	"STK_interface.h"
#include	"STK_config.h"
#include	"STK_private.h"


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function to initialize SysTick		 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void STK_voidInit(void)
{
	#if	STK_CLOCK_TYPE == CLOCK_AHB
		SET_BIT(STK->CTRL, 2);
	#elif	STK_CLOCK_TYPE == CLOCK_AHB_DIVIDED_BY_8
		CLEAR_BIT(STK->CTRL, 2);
	#else
		#error	"Wrong Choice"
	#endif
	
	CLEAR_BIT(STK->CTRL, 1);
	
	CLEAR_BIT(STK->CTRL, 0);
}



/************************************************************/
/* Description :  function to set Ticks without interrupt	*/
/*				  input	 :	u32 copy_u32Ticks				*/
/*				  output :	void							*/
/************************************************************/	
void STK_voidSetBusyWait(u32 copy_u32Ticks)
{
	
	
	STK->LOAD = copy_u32Ticks;
	SET_BIT(STK->CTRL, 0);
	
	/**				Wait till Flag is raised				*/
	while(GET_BIT(STK->CTRL, 16)  == 0);
	
	/**				Stop Timer								*/
	SET_BIT(STK->CTRL, 0);
	STK->VAL 	= 0;
	STK->LOAD 	= 0;
}



/************************************************************/
/* Description :  function to set single interval 			*/
/*				   with interrupt		 					*/
/*				  input	 :	u32 copy_u32Ticks,				*/
/*							void (*copy_ptr)(void)			*/
/*				  output :	void							*/
/************************************************************/	
void STK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr)(void))
{
	/**				Disable Timer if it Running 			*/
	CLEAR_BIT(STK->CTRL, 0);
	STK->VAL 	= 0;
	
	STK->LOAD = copy_u32Ticks;
	
	/**				Start Timer								*/
	SET_BIT(STK->CTRL, 0);
	
	/**				Set Call Back Function					*/
	STK_CallBack = copy_ptr;
	
	STK_u8IntervalMode = SINGLE_INTERVAL;
	
	/**				Enable Timer Interrupt					*/
	SET_BIT(STK->CTRL, 1);
}




/************************************************************/
/* Description :  function to set multi interval 			*/
/*				   with interrupt		 					*/
/*				  input	 :	u32 copy_u32Ticks,				*/
/*							void (*copy_ptr)(void)			*/
/*				  output :	void							*/
/************************************************************/
void STK_voidSetIntervalperiodic(u32 copy_u32Ticks, void (*copy_ptr)(void))
{
	STK->LOAD = copy_u32Ticks;
	/**				Start Timer								*/
	SET_BIT(STK->CTRL, 0);
	
	/**				Set Call Back Function					*/
	STK_CallBack = copy_ptr;
	
	STK_u8IntervalMode = PERIODIC_INTERVAL;
	
	/**				Enable Timer							*/
	SET_BIT(STK->CTRL, 1);
	
}



/************************************************************/
/* Description :  function to stop Timer				 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	
void STK_voidStopTimer(void)
{
	/**				Disable Interrupt						*/
	CLEAR_BIT(STK->CTRL, 1);
	
	/**				Start Timer								*/
	SET_BIT(STK->CTRL, 0);
	STK->VAL  = 0;
	STK->LOAD  = 0;
}



/************************************************************/
/* Description :  function to get elapsed time			 	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/	
u32 STK_u32GetElapsedTime(void)
{
	u32 Local_ElapsedTime = 0;
	
	Local_ElapsedTime = STK->LOAD - STK->VAL;
	
	return	Local_ElapsedTime;
}



/************************************************************/
/* Description :  function to get Remaning time			 	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/	
u32 STK_u32GetRemaningTime(void)
{
	u32 Local_ElapsedTime = 0;
	
	Local_ElapsedTime = STK->VAL;
	
	return	Local_ElapsedTime;
}



/************************************************************/
/* Description :  function to Set Interrupt service 		*/
/*				  routine (ISR) of SysTick			 		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	
void SysTick_Handler(void)
{
	u8 Local_u8Temp;
	if(STK_u8IntervalMode == SINGLE_INTERVAL)
	{
	/**				Disable Interrupt						*/
	CLEAR_BIT(STK->CTRL, 1);
	
	/**				Start Timer								*/
	SET_BIT(STK->CTRL, 0);
	STK->VAL  = 0;
	STK->LOAD  = 0;
	}
	
	STK_CallBack();
	/**				Clear Interrupt Flag 					*/
	Local_u8Temp = GET_BIT(STK->CTRL, 16) ;
}