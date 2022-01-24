/************************************************************/
/**   		AUTHOR      : Mohamed	MeGa	              	*/
/**   		Description : GPIO DRIVER                     	*/
/**   		DATE        : 08 DEC 2021                   	*/
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
#include	"GPIO_interface.h"
#include	"GPIO_config.h"
#include	"GPIO_private.h"


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function to set the direction of any pin	*/
/*				  input	 :	u8	copy_u8Port,				*/
/*							u8 copy_u8Pin,					*/
/*							u8 copy_u8Mode					*/
/*				  output :	void							*/
/************************************************************/	 
void	GPIO_VoidSetPinDirection(u8	copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode)
{
	switch (copy_u8Port) 
	{
		case	GPIOA :
			if(copy_u8Pin <= 7)
			{
				GPIOA_CRL	&= ~((0b0000) << (copy_u8Pin * 4));
				GPIOA_CRL	|= ((copy_u8Mode) << (copy_u8Pin * 4));
			}
			else if(copy_u8Pin <= 15)
			{
				copy_u8Pin 	= copy_u8Pin - 8;
				GPIOA_CRH	&= ~((0b0000) << (copy_u8Pin * 4));
				GPIOA_CRH	|= ((copy_u8Mode) << (copy_u8Pin * 4));
			}
			break;
		case	GPIOB :
			if(copy_u8Pin <= 7)
			{
				GPIOB_CRL	&= ~((0b0000) << (copy_u8Pin * 4));
				GPIOB_CRL	|= ((copy_u8Mode) << (copy_u8Pin * 4));
			}
			else if(copy_u8Pin <= 15)
			{
				copy_u8Pin 	= copy_u8Pin - 8;
				GPIOB_CRH	&= ~((0b0000) << (copy_u8Pin * 4));
				GPIOB_CRH	|= ((copy_u8Mode) << (copy_u8Pin * 4));
			}
			break;
		case	GPIOC :
			if(copy_u8Pin <= 7)
			{
				GPIOC_CRL	&= ~((0b0000) << (copy_u8Pin * 4));
				GPIOC_CRL	|= ((copy_u8Mode) << (copy_u8Pin * 4));
			}
			else if(copy_u8Pin <= 15)
			{
				copy_u8Pin 	= copy_u8Pin - 8;
				GPIOC_CRH	&= ~((0b0000) << (copy_u8Pin * 4));
				GPIOC_CRH	|= ((copy_u8Mode) << (copy_u8Pin * 4));
			}
			break;
	}
}



/************************************************************/
/* Description :  function to set the direction of any pin	*/
/*				  input	 :	u8	copy_u8Port,				*/
/*							u8 copy_u8Pin,					*/
/*							u8 copy_u8Value					*/
/*				  output :	void							*/
/************************************************************/	
void	GPIO_VoidSetPinValue(u8	copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	switch (copy_u8Port)
	{
		case GPIOA :
			if(copy_u8Value	==	GPIO_HIGH)
			{
				SET_BIT(GPIOA_ODR, copy_u8Pin);
			}
			else if(copy_u8Value	==	GPIO_LOW)
			{
				CLEAR_BIT(GPIOA_ODR, copy_u8Pin);
			}
			break;
		
		case GPIOB :
			if(copy_u8Value	==	GPIO_HIGH)
			{
				SET_BIT(GPIOB_ODR, copy_u8Pin);
			}
			else if(copy_u8Value ==	GPIO_LOW)
			{
				CLEAR_BIT(GPIOB_ODR, copy_u8Pin);
			}
			break;
		
		case GPIOC :
			if(copy_u8Value	==	GPIO_HIGH)
			{
				SET_BIT(GPIOC_ODR, copy_u8Pin);
			}
			else if(copy_u8Value	==	GPIO_LOW)
			{
				CLEAR_BIT(GPIOC_ODR, copy_u8Pin);
			}
			break;
	}
}


/************************************************************/
/* Description :  function for Enable Clock 				*/
/*				  input	 :	u8	copy_u8Port,				*/
/*							u8 copy_u8Pin,					*/
/*				  output :	u8								*/
/************************************************************/	
u8		GPIO_u8GetPinValue(u8	copy_u8Port, u8 copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	switch (copy_u8Port)
	{
		case GPIOA :
			LOC_u8Result = GET_BIT(GPIOA_IDR, copy_u8Pin);
			break;
		
		case GPIOB :
			LOC_u8Result = GET_BIT(GPIOB_IDR, copy_u8Pin);
			break;
		
		case GPIOC :
			LOC_u8Result = GET_BIT(GPIOC_IDR, copy_u8Pin);
			break;
		default:
			break;
	}	
	return	LOC_u8Result;
}

/************************************************************/
/* Description :  function for Enable Clock 				*/
/*				  input	 :	u8	copy_u8Port,				*/
/*							u8 copy_u8Pin,					*/
/*							u8 copy_u8Lock					*/
/*				  output :	void							*/
/************************************************************/	
void		GPIO_u8LockPinConfig(u8	copy_u8Port, u8 copy_u8Pin, u8 copy_u8Lock)
{
	switch (copy_u8Port)
	{
		case GPIOA :
			if(copy_u8Lock	==	GPIO_LOCK)
			{
				SET_BIT(GPIOA_LCK, copy_u8Pin);
			}
			else if(copy_u8Lock	==	GPIO_UNLOCK)
			{
				CLEAR_BIT(GPIOA_LCK, copy_u8Pin);
			}
			break;
		
		case GPIOB :
			if(copy_u8Lock	==	GPIO_LOCK)
			{
				SET_BIT(GPIOA_LCK, copy_u8Pin);
			}
			else if(copy_u8Lock ==	GPIO_UNLOCK)
			{
				CLEAR_BIT(GPIOA_LCK, copy_u8Pin);
			}
			break;
		
		case GPIOC :
			if(copy_u8Lock	==	GPIO_LOCK)
			{
				SET_BIT(GPIOA_LCK, copy_u8Pin);
			}
			else if(copy_u8Lock	==	GPIO_UNLOCK)
			{
				CLEAR_BIT(GPIOA_LCK, copy_u8Pin);
			}
			break;
	}
}