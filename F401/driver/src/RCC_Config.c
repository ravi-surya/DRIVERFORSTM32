/*
 * RCC_Config.c
 *
 *  Created on: Feb 3, 2024
 *      Author: ravis
 */

#include "RCC_Config.h"

void SysClockConfig(void);



void SysClockConfig(void)
{


/*
 * *********************************************************
 * steps followed for SYSCLOCKCONFIG
 * **********************************************************
 * 1.enable the HSE and WAIT for the HSE TO become ready
 * 2.set the POWER ENABLE CLOCK AND VOLTAGE REGULATOR
 * 3.configure the FLASH PREFETCH and the LATENCY related setting
 * 4.configure the PRESCALARS PCLK ,PCLK1 ,PCLK2
 * 5.configure the main PLL
 * 6.enable the PLL and wait for it to become ready
 * 7.select the clock source and wait for it to be set
 * ***********************************************************
 *
 */
#define PLL_M 4
#define PLL_N 84
#define PLL_P 0 //VERY IMPORTANT WHY THIS IS 0

//1.enable the HSE and WAIT for the HSE TO become ready
RCC->CR |= RCC_CR_HSEON;
while(!(RCC->CR & RCC_CR_HSERDY));

//2.set the POWER ENABLE CLOCK AND VOLTAGE REGULATOR
RCC->APB1ENR |=RCC_APB1ENR_PWREN;
//PWR_CR POWER  CONTROL REGISTER keep it at reset
PWR->CR |= PWR_CR_VOS;

//3.configure the FLASH PREFETCH and the LATENCY related setting
//flash interface registers
FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN;
FLASH->ACR |= FLASH_ACR_LATENCY_2WS;

//4.configure the PRESCALARS PCLK ,PCLK1 ,PCLK2
//RCC clock configuration register
//ahb1
RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
//apb1
RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
//apb2
RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

//5.configure the main PLL
//RCC PLL configuration register
RCC->PLLCFGR |= (PLL_M<<0) | (PLL_N<<6) | (PLL_P<<16);
//SELECT SRC AS WELL
RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;

//6.enable the PLL and wait for it to become ready
//RCC clock control register
RCC->CR |= RCC_CR_PLLON;
while(!(RCC->CR & RCC_CR_PLLRDY));

//7.select the clock source and wait for it to be set
//clock configuration register
RCC->CFGR |= RCC_CFGR_SW_PLL;
while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}
