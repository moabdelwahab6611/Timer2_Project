/* 
 * File     : application.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on May 21, 2023, 5:38 PM
 */

/**************************Includes-Section*****************************/
#include "application.h"
#include "MCAL_Layer/Timer2/hal_timer2.h"
/***********************************************************************/

/***********************************************************************/
timer2_t timer2_obj;

volatile uint32 timer2_flag;

void Timer2_DefaultInterrruptHandler(void)
{
    ++timer2_flag;
}
/***********************************************************************/

/***********************Main Function-Section***************************/
int main() 
{ 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    
    timer2_obj.TMR2_InterruptHandler = Timer2_DefaultInterrruptHandler;
    timer2_obj.priority = INTERRUPT_LOW_PRIORITY;
    timer2_obj.timer2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1;
    timer2_obj.timer2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_16;
    timer2_obj.timer2_preload_value = 249;
    ret = Timer2_Init(&timer2_obj);
    while(1)
    {   
       
    }
    return (EXIT_SUCCESS);
}
/***********************************************************************/

/*************************Functions-Section*****************************/
void application_intialize(void)
{
    Std_ReturnType ret = E_NOT_OK;   
    ecu_layer_intialize();
}
/***********************************************************************/