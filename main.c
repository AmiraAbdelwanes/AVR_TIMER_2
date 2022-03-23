#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
/***********************DIO*******************/
#include "DIO_register.h"
#include "DIO_interface.h"
/***********************TIM_2*****************/
#include "TIM2_REG.h"
#include "Tim2_confg.h"
#include "TIM2_int.h"



void main ()
{
	DIO_enumSetPinDirection(DIO_U8_PORT_D,DIO_U8_PIN7 , DIO_U8_OUTPUT); //OC2

	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN5 , DIO_U8_OUTPUT);//Main_LED Indicator


	//ENABLE GIF
	SET_BIT(SREG,7);
	Timer2_Init( TIMER2_PHASECORRECT_MODE,TIMER2_SCALER_1 ,OC2_NON_INVERTING);
	Timer2_OC_InterruptEnable();
	OCR2=127;


	while (1)
	{
		DIO_enumSetPinValue( DIO_U8_PORT_B ,DIO_U8_PIN5,DIO_U8_HIGH  );
		_delay_ms(500);
		DIO_enumSetPinValue( DIO_U8_PORT_B ,DIO_U8_PIN5,DIO_U8_LOW   );
		_delay_ms(500);
	}


}


