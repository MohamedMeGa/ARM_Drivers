/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : NVIC DRIVER                     	*/
/**   		DATE        : 12 DEC 2021                   	*/
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
#include	"NVIC_interface.h"
#include	"NVIC_config.h"
#include	"NVIC_private.h"


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function for Enable Interrupt 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	 
void	NVIC_VoidEnableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32;
		NVIC_ISER0 = 1 << copy_u8IntNumber;
	}
	else
	{
		/*	return	Error	*/
	}
}



/************************************************************/
/* Description :  function for Disable Interrupt 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidDisableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32;
		NVIC_ICER1 = 1 << copy_u8IntNumber;
	}
	else
	{
		/*	return	Error	*/
	}
}


/************************************************************/
/* Description :  function for Set Pending Flag 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidSetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32;
		NVIC_ISPR1 = 1 << copy_u8IntNumber;
	}
	else
	{
		/*	return	Error	*/
	}
}



/************************************************************/
/* Description :  function for Clear Pending Flag 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidClearPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32;
		NVIC_ICPR1 = 1 << copy_u8IntNumber;
	}
	else
	{
		/*	return	Error	*/
	}
}



/************************************************************/
/* Description :  function for Clear Pending Flag 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	u8								*/
/************************************************************/	
u8	NVIC_U8GetActiveFlag(u8 copy_u8IntNumber)
{
	u8 LOC_u8Result = 0;
	if(copy_u8IntNumber <= 31)
	{
		LOC_u8Result = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32;
		LOC_u8Result = GET_BIT(NVIC_IABR1, copy_u8IntNumber);
	}
	else
	{
		/*	return	Error	*/
	}
	
	return	LOC_u8Result;
}


/************************************************************/
/* Description :  function for Clear Pending Flag 			*/
/*				  input	 :	s8 copy_s8IntID,				*/
/*							u8 copy_u8GroupPriority,		*/
/*							u8 copy_u8SubGroupPriority,		*/
/*							u32 copy_u32Group				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidSetPriority(s8 copy_s8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubGroupPriority, u32 copy_u32Group)
{
	u8 Local_u8priority = copy_u8SubGroupPriority||(copy_u8GroupPriority << ((copy_u32Group - 0x05FA0300)/256));
	
	if(copy_s8IntID >= 0)
	{
		IPR[copy_s8IntID] = Local_u8priority << 4;
	}
	SCB_AIRCR = copy_u32Group;
}