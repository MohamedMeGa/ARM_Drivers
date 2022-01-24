/************************************************************/
/* 			AUTHOR      : Mohamed MeGa	                  	*/
/* 			DISCRIPTION : LEDMRX DRIVER                     */
/* 			DATE        : 19 DEC 2021                       */
/* 			VERSION     : V01                               */
/************************************************************/

void	LEDMRX_VoidInt(void)
{
	GPIO_VoidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_2MHZ_PP);
	
	GPIO_VoidSetPinDirection(LEDMRX_COL0_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL1_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL2_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL3_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL4_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL5_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL6_PIN, OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(LEDMRX_COL7_PIN, OUTPUT_2MHZ_PP);
}

void	LEDMRX_VoidDisplay(u8 * copy_u8Data)
{
	LEDMRX_VoidDisableAllColumns();
	
	GPIO_VoidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[0]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[1]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[2]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[3]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[4]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[5]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[6]);
	STK_voidSetBusyWait(2500);
	
	GPIO_VoidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
	LEDMRX_VoidSetRowValue(copy_u8Data[7]);
	STK_voidSetBusyWait(2500);
}



void LEDMRX_VoidDisableAllColumns()
{
	GPIO_VoidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
	GPIO_VoidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}



void LEDMRX_VoidSetRowValue(u8 copy_u8Data)
{
	u8 Local_u8Bit = 0;
	
	Local_u8Bit = GET_BIT(copy_u8Data, 0);
	GPIO_VoidSetPinValue(LEDMRX_ROW0_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 1);
	GPIO_VoidSetPinValue(LEDMRX_ROW1_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 2);
	GPIO_VoidSetPinValue(LEDMRX_ROW2_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 3);
	GPIO_VoidSetPinValue(LEDMRX_ROW3_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 4);
	GPIO_VoidSetPinValue(LEDMRX_ROW4_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 5);
	GPIO_VoidSetPinValue(LEDMRX_ROW5_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 6);
	GPIO_VoidSetPinValue(LEDMRX_ROW6_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(copy_u8Data, 7);
	GPIO_VoidSetPinValue(LEDMRX_ROW7_PIN, Local_u8Bit);
}