/*
 * LEDx_blink.c
 *
 *  Created on: May 19, 2019
 *      Author: jvbx0
 */

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "LEDx_blink.h"
#include "LCD_1602A.h"


extern osMutexId mt_LCD_freeHandle;

/* Header_vStart_tsk_LEDx_blink */
/**
* @brief Function implementing the tsk_LED1_blink thread.
* @param argument: Not used
* @retval None
*/
/* Header_vStart_tsk_LEDx_blink */
void vStart_tsk_LEDx_blink(const void * argument)
{

uint8_t *arg = (uint8_t*)argument;

  /* Infinite loop */
  for(;;)
  {
      if (arg == 0)
          {
          if(osSemaphoreWait(mt_LCD_freeHandle, 0) == osOK) {
          LCD1602A_ClearScreen(); //Очистка дисплея от мусора
          LCD1602A_SetCursorPos(0, 1); //Установка курсора
          LCD1602A_PrintStr("LED1Task_enter" + '\0');
          osSemaphoreRelease(mt_LCD_freeHandle);}
          //uint8_t flag1 = 1;
          LED1_TOGGLE();
          //flag1 = 0;
          osDelay(100);
          if(osSemaphoreWait(mt_LCD_freeHandle, 0) == osOK) {
          LCD1602A_ClearScreen(); //Очистка дисплея от мусора
          LCD1602A_SetCursorPos(0, 1); //Установка курсора
          LCD1602A_PrintStr("LED1Task_exit" + '\0');
          osSemaphoreRelease(mt_LCD_freeHandle);}
          taskYIELD();
          } else
                {
              if(osSemaphoreWait(mt_LCD_freeHandle, 0) == osOK) {
                               LCD1602A_ClearScreen(); //Очистка дисплея от мусора
                               LCD1602A_SetCursorPos(1, 1); //Установка курсора
                               LCD1602A_PrintStr("LED2Task_enter" + '\0');
                               osSemaphoreRelease(mt_LCD_freeHandle);}
                 //uint8_t flag2 = 1;
                 LED2_TOGGLE();
                 //flag2 = 0;
                 osDelay(230);
                 if(osSemaphoreWait(mt_LCD_freeHandle, 0) == osOK) {
                 LCD1602A_ClearScreen(); //Очистка дисплея от мусора
                 LCD1602A_SetCursorPos(1, 1); //Установка курсора
                 LCD1602A_PrintStr("LED2Task_exit" + '\0');
                 osSemaphoreRelease(mt_LCD_freeHandle);}
                taskYIELD();
                }
  }

}
