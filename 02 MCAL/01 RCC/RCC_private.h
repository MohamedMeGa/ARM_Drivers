/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa           		  	*/
/*   		Description : RCC DRIVER                     	*/
/*   		DATE        : 05 DEC 2021                   	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	RCC_PRIV_H
#define	RCC_PRIV_H


/************************************************************/
/**			Register  	DEFINITION							*/
/************************************************************/
#define	RCC_CR			*((u32 	*)0x40021000)
#define	RCC_CFGR		*((u32	*)0x40021004)
#define	RCC_CIR			*((u32	*)0x40021008)
#define	RCC_ABP2RSTR	*((u32	*)0x4002100C)
#define	RCC_ABP1RSTR	*((u32	*)0x40021010)
#define	RCC_AHBENR		*((u32	*)0x40021014)
#define	RCC_ABP2ENR		*((u32	*)0x40021018)
#define	RCC_ABP1ENR		*((u32	*)0x4002101C)
#define	RCC_BDCR		*((u32	*)0x40021020)
#define	RCC_CSR			*((u32	*)0x40021024)



/************************************************************/
/**				Clock	Type								*/
/************************************************************/
#define	RCC_HSI				0
#define	RCC_HSE_CRYSTAL		1
#define	RCC_HSE_RC			2
#define	RCC_PLL				3




/************************************************************/
/**				PLL	Input	Type							*/
/************************************************************/
#define	PLL_HSI_DIVBY_2		0
#define	PLL_HSE				1	
#define	PLL_HSE_DIVBY_2		2


/************************************************************/
/**				PLL	Multiplication  Factor					*/
/************************************************************/
#define	PLL_MUL_BY_2     0                 
#define PLL_MUL_BY_3     1                
#define PLL_MUL_BY_4     2                 
#define PLL_MUL_BY_5     3               
#define PLL_MUL_BY_6     4                 
#define PLL_MUL_BY_7     5               
#define PLL_MUL_BY_8     6                
#define PLL_MUL_BY_9     7                 
#define PLL_MUL_BY_10    8                 
#define PLL_MUL_BY_11    9                 
#define PLL_MUL_BY_12    10                 
#define PLL_MUL_BY_13    11                 
#define PLL_MUL_BY_14    12                 
#define PLL_MUL_BY_15    13                 
#define PLL_MUL_BY_16	 14


#endif