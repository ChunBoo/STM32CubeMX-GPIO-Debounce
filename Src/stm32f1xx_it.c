/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "stm32f1xx_it.h"

/* USER CODE BEGIN 0 */
uint8_t sw1Count,sw2Count,sw3Count,sw4Count;
uint8_t pushFlag1,pushFlag2,pushFlag3,pushFlag4;
extern uint8_t swState1,swState2,swState3,swState4;
 void Key_Scan(void)
{
         /*检测SW1是否按下 */
         if(   HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin) == GPIO_PIN_RESET )
         {
                 sw1Count++;                         //SW1键按下，计数sw1Count加1
                 if(sw1Count>=32)                    //1MS中断一次，sw1Count大于等于50，即按键已按下32ms
                 {
                         if(pushFlag1==0)                //判断有没有重按键，1为有，0为没有
                        {
                        swState1=1;                       //设置按键标志
                        sw1Count=0;
                        pushFlag1=1;                     //设置重按键标志
                        }
                        else
                        sw1Count=0;
                 }
                 else
                	    swState1=0;

         }
         else                                            //无按键按下
         {
                 sw1Count=0;                           //清零sw1Count
                 swState1=0;                            //清除按键标志
                 pushFlag1=0;                          //清除重按键标志
         }

         /*检测SW2是否按下 */
         if(   HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin) == GPIO_PIN_RESET )
         {
                 sw2Count++;                         //SW2键按下，计数sw2Count加1
                 if(sw2Count>=32)                    //1MS中断一次，sw2Count大于等于50，即按键已按下32ms
                 {
                         if(pushFlag2==0)                //判断有没有重按键，1为有，0为没有
                        {
                        swState2=1;                       //设置按键标志
                        sw2Count=0;
                        pushFlag2=1;                     //设置重按键标志
                        }
                        else
                        sw2Count=0;
                 }
                 else
                	    swState2=0;

         }
         else                                            //无按键按下
         {
                 sw2Count=0;                           //清零sw2Count
                 swState2=0;                            //清除按键标志
                 pushFlag2=0;                          //清除重按键标志
         }

         /*检测SW3是否按下 */
         if(   HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin) == GPIO_PIN_RESET )
         {
                 sw3Count++;                         //SW3键按下，计数sw3Count加1
                 if(sw3Count>=32)                    //1MS中断一次，sw3Count大于等于50，即按键已按下32ms
                 {
                         if(pushFlag3==0)                //判断有没有重按键，1为有，0为没有
                        {
                        swState3=1;                       //设置按键标志
                        sw3Count=0;
                        pushFlag3=1;                     //设置重按键标志
                        }
                        else
                        sw3Count=0;
                 }
                 else
                	    swState3=0;

         }
         else                                            //无按键按下
         {
                 sw3Count=0;                           //清零sw3Count
                 swState3=0;                            //清除按键标志
                 pushFlag3=0;                          //清除重按键标志
         }

         /*检测SW4是否按下 */
         if(   HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin) == GPIO_PIN_RESET )
         {
                 sw4Count++;                         //SW4键按下，计数sw4Count加1
                 if(sw4Count>=32)                    //1MS中断一次，sw4Count大于等于50，即按键已按下32ms
                 {
                         if(pushFlag4==0)                //判断有没有重按键，1为有，0为没有
                        {
                        swState4=1;                       //设置按键标志
                        sw4Count=0;
                        pushFlag4=1;                     //设置重按键标志
                        }
                        else
                        sw4Count=0;
                 }
                 else
                	    swState4=0;

         }
         else                                            //无按键按下
         {
                 sw4Count=0;                           //清零sw4Count
                 swState4=0;                            //清除按键标志
                 pushFlag4=0;                          //清除重按键标志
         }

}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Prefetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	Key_Scan();
  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
