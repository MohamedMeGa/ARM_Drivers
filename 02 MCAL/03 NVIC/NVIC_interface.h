/************************************************************/
/*   		AUTHOR      : MOHAMED	MEGA	              	*/
/*   		Description : NVIC DRIVER                     	*/
/*   		DATE        : 12 DEC 2021                    	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	NVIC_INT_H
#define	NVIC_INT_H




/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function for Enable Interrupt 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	 
void	NVIC_VoidEnableInterrupt(u8 copy_u8IntNumber);



/************************************************************/
/* Description :  function for Disable Interrupt 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidDisableInterrupt(u8 copy_u8IntNumber);


/************************************************************/
/* Description :  function for Set Pending Flag 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidSetPendingFlag(u8 copy_u8IntNumber);



/************************************************************/
/* Description :  function for Clear Pending Flag 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidClearPendingFlag(u8 copy_u8IntNumber);



/************************************************************/
/* Description :  function for Clear Pending Flag 			*/
/*				  input	 :	u8 copy_u8IntNumber				*/
/*				  output :	u8								*/
/************************************************************/	
u8	NVIC_U8GetActiveFlag(u8 copy_u8IntNumber);


/************************************************************/
/* Description :  function for Clear Pending Flag 			*/
/*				  input	 :	s8 copy_s8IntID,				*/
/*							u8 copy_u8GroupPriority,		*/
/*							u8 copy_u8SubGroupPriority,		*/
/*							u32 copy_u32Group				*/
/*				  output :	void							*/
/************************************************************/	
void	NVIC_VoidSetPriority(s8 copy_s8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubGroupPriority, u32 copy_u32Group);




/************************************************************/
/**				Grouping	Defination						*/
/************************************************************/
#define		GROUP3		0x05FA0300	//4 bits for group (IPR)	=>	group
#define		GROUP4		0x05FA0400	//3 bits for group and 1 bit for sub group 
#define		GROUP5		0x05FA0500	//2 bits for group and 2 bit for sub group 
#define		GROUP6		0x05FA0600	//1 bits for group and 3 bit for sub group
#define		GROUP7		0x05FA0700	//0 bits for group and 4 bit for sub group  



#endif
