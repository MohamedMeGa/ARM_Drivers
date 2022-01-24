/************************************************************/
/*   		AUTHOR      : MOHAMED	MEGA	              	*/
/*   		Description : EXTI DRIVER                     	*/
/*   		DATE        : 13 DEC 2021                    	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	EXTI_INT_H
#define	EXTI_INT_H




/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function for Initialize Ext Interrupt 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	 
void	EXTI_VoidInit();



/************************************************************/
/* Description :  function to Enable External Interrupt 	*/
/*				  input	 :	u8 copy_u8EXTILine				*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidEnableEXTI(u8 copy_u8EXTILine);


/************************************************************/
/* Description :  function to Disable External Interrupt	*/
/*				  input	 :	u8 copy_u8EXTILine				*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidDisableEXTI(u8 copy_u8EXTILine);



/************************************************************/
/* Description :  function for Set Pending Flag 			*/
/*				this flag cleared after clearing 			*/
/*				pending flag								*/
/*				  input	 :	u8 copy_u8EXTILine				*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidSWTrigger(u8 copy_u8EXTILine);




/************************************************************/
/* Description :  function to change the Mode of 			*/
/*					selected line 							*/
/*				  input	 :	u8 copy_u8EXTILine,				*/
/*							u8 copy_u8Mode					*/
/*				  output :	void							*/
/************************************************************/	
void	EXTI_VoidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8Mode);



void EXTI_VoidSetCallBack(void(* copy_ptr)(void));

#endif