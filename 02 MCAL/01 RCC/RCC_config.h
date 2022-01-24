/************************************************************/
/* 			AUTHOR      : Mohamed MeGa	                  	*/
/* 			DISCRIPTION : RCC DRIVER                        */
/* 			DATE        : 05 DEC 2021                       */
/* 			VERSION     : V01                               */
/************************************************************/

#ifndef	RCC_CONFIG_H
#define	RCC_CONFIG_H


/******************************************************************/
/*                                                                */
/*                    ClockType Maybe :       	                  */
/*                       1-RCC_HSI                                */
/*                       2-RCC_HSE_CRYSTAL                        */
/*                       3-RCC_HSE_RC                             */
/*                       4-RCC_PLL	                              */
/*                                                                */
/******************************************************************/
#define		RCC_CLOCK_TYPE		RCC_HSI

/********************************************************************/
/*                                                                 	*/
/*							PLL_Source           	             	*/
/*                               1-PLL_HSI_DIVBY_2		          	*/
/*                               2-PLL_HSE           	        	*/
/*                               3-PLL_HSE_DIVBY_2		          	*/
/*                       				                           	*/
/********************************************************************/
#if	RCC_CLOCK_TYPE	==	RCC_PLL
	#define	RCC_PLL_SOURCE_TYPE		PLL_HSI_DIVBY_2
#endif





/**********************************************************/
/*       PLL Multiplication factor :		              */
/*                      PLL_MUL_BY_2                      */
/*                      PLL_MUL_BY_3                      */
/*                      PLL_MUL_BY_4                      */
/*                      PLL_MUL_BY_5                      */
/*                      PLL_MUL_BY_6                      */
/*                      PLL_MUL_BY_7                      */
/*                      PLL_MUL_BY_8                      */
/*                      PLL_MUL_BY_9                      */
/*                      PLL_MUL_BY_10                     */
/*                      PLL_MUL_BY_11                     */
/*                      PLL_MUL_BY_12                     */
/*                      PLL_MUL_BY_13                     */
/*                      PLL_MUL_BY_14                     */
/*                      PLL_MUL_BY_15                     */
/*                      PLL_MUL_BY_16                     */
/**********************************************************/
#define		RCC_PLL_MUL_FAC			PLL_MUL_BY_16

/**********************************************************************/
/*                                                                    */
/*                 Clock Security System May be                       */
/*                 1-ENABLE_CLK_SECURITY:                             */
/* 				  	-To Set HSI By H.W When There are Failure In HSE  */
/* 				    -To Set HSI By H.W When Leaving Stop Or Standby   */
/*																	  */
/* 				   2-DISABLE_CLK_SECURITY                             */
/* 				    -The Previouse Feature Does not Happen            */
/*                                                                    */
/**********************************************************************/
#define		CLOCK_SECURITY		DISABLE_CLK_SECURITY

#endif