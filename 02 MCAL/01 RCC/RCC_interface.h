/************************************************************/
/*   		AUTHOR      : MOHAMED	MEGA	              	*/
/*   		Description : RCC DRIVER                     	*/
/*   		DATE        : 05 DEC 2021                    	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	RCC_INT_H
#define	RCC_INT_H



#define RCC_AHB       0 
#define RCC_ABP1      1
#define RCC_ABP2      2



/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function for initialization The RCC		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/	 
void	RCC_VoidInitSystemClock(void);



/************************************************************/
/* Description :  function for Enable Clock 				*/
/*				  input	 :	u8	copy_u8BusID,				*/
/*							u8	copy_u8PeriherialID			*/
/*				  output :	void							*/
/************************************************************/	
void	RCC_VoidEnableClock(u8	copy_u8BusID, u8	copy_u8PeriherialID);


/************************************************************/
/* Description :  function for Enable Clock 				*/
/*				  input	 :	u8	copy_u8BusID,				*/
/*							u8	copy_u8PeriherialID			*/
/*				  output :	void							*/
/************************************************************/	
void	RCC_VoidDisableClock(u8	copy_u8BusID, u8	copy_u8PeriherialID);

#endif
