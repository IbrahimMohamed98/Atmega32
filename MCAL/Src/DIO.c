/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  General purpose IO's Driver
 *
 *      \details -Initiation of a pin with it's direction
 *               -Write the pin Logic Level either high or low
 *               -Read the pin Logic level
 *               -Toggles a pin
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../libs/BitMath.h"
#include "../../libs/BitMath.h"
#include "../../libs/Registers.h"

#include "../Inc/DIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void DIO_init(IOPort_t *port,PinNum_t pin,PinDirection_t direction){
	if (direction == OUT)
	{
		BIT_SET(port -> DIR,pin);
	}else{
		BIT_CLR(port -> DIR,pin);
	}
	
}

void DIO_setPinValue(IOPort_t *port,PinNum_t pin,PinValue_t value){
	if (value == HIGH_OUT)
	{
		BIT_SET(port -> OUT,pin);
	}else{
		BIT_CLR(port -> DIR,pin);
	}
}

void DIO_togglePin(IOPort_t *port,PinNum_t pin){
	BIT_TGL(port -> OUT,pin);//Toggles the pin value
}

PinValue_t DIO_readPin(IOPort_t *port,PinNum_t pin){
	return BIT_VAL(port->IN,pin);//returns the pin value.
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
