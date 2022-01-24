/************************************************************/
/*   		AUTHOR      : MOHAMED	MEGA	              	*/
/*   		Description : SysTick DRIVER                    */
/*   		DATE        : 15 DEC 2021                    	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	STK_INT_H
#define	STK_INT_H

#define	CLOCK_AHB					0
#define	CLOCK_AHB_DIVIDED_BY_8		1

#define	SINGLE_INTERVAL				2
#define	PERIODIC_INTERVAL			3



/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function to initialize SysTick		 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/		 
void STK_voidInit(void);



/************************************************************/
/* Description :  function to set Ticks without interrupt	*/
/*				  input	 :	u32 copy_u32Ticks				*/
/*				  output :	void							*/
/************************************************************/	
void STK_voidSetBusyWait(u32 copy_u32Ticks);



/************************************************************/
/* Description :  function to set single interval 			*/
/*				   with interrupt		 					*/
/*				  input	 :	u32 copy_u32Ticks,				*/
/*							void (*copy_ptr)(void)			*/
/*				  output :	void							*/
/************************************************************/	
void STK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr)(void));




/************************************************************/
/* Description :  function to set multi interval 			*/
/*				   with interrupt		 					*/
/*				  input	 :	u32 copy_u32Ticks,				*/
/*							void (*copy_ptr)(void)			*/
/*				  output :	void							*/
/************************************************************/
void STK_voidSetIntervalperiodic(u32 copy_u32Ticks, void (*copy_ptr)(void));



/************************************************************/
/* Description :  function to stop Timer				 	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	
void STK_voidStopTimer(void);



/************************************************************/
/* Description :  function to get elapsed time			 	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/	
u32 STK_u32GetElapsedTime(void);



/************************************************************/
/* Description :  function to get Remaning time			 	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/	
u32 STK_u32GetRemaningTime(void);








#endif
