/**
 * @file rcc_driver.h
 * @author Dominick Green
 * @brief RCC driver header file
 * @version 0.1
 * @date 2024-06-05
 */

#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H 

#include <stdint.h>
#include <stddef.h>

/**
 * @brief RCC base address for clock control
 */
#define RCC ((RCC_t *)0x40023800UL)

/**
 * @brief RCC register structure definition
 */
typedef struct{
    volatile uint32_t CR; /**< Clock control register */
    volatile uint32_t PLL_CFGR; /**< PLL configuration register */
    volatile uint32_t CFGR; /**< Clock configuration register */
    volatile uint32_t CIR; /**< Clock interrupt register */
    volatile uint32_t AHB1RSTR; /**< AHB1 reset register */
    volatile uint32_t AHB2RSTR; /**< AHB2 reset register */
    volatile uint32_t AHB3RSTR; /**< AHB3 reset register */
    uint32_t RESERVED0; 
    volatile uint32_t APB1RSTR; /**< APB1 reset register */
    volatile uint32_t APB2RSTR; /**< APB2 reset register */
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR; /**< AHB1 enable register */
    volatile uint32_t AHB2ENR; /**< AHB2 enable register */
    volatile uint32_t AHB3ENR; /**< AHB3 enable register */
    uint32_t RESERVED2;
    volatile uint32_t APB1ENR; /**< APB1 enable register */
    volatile uint32_t APB2ENR; /**< APB2 enable register */
    uint32_t RESERVED3[2];
    volatile uint32_t AHB1LPENR; /**< AHB1 low power enable register */
    volatile uint32_t AHB2LPENR; /**< AHB2 low power enable register */
    volatile uint32_t AHB3LPENR; /**< AHB3 low power enable register */
    uint32_t RESERVED4;
    volatile uint32_t APB1LPENR; /**< APB1 low power enable register */
    volatile uint32_t APB2LPENR; /**< APB2 low power enable register */
    uint32_t RESERVED5[2];
    volatile uint32_t BDCR; /**< Backup domain control register */
    volatile uint32_t CSR; /**< Control/status register */
    uint32_t RESERVED6[2];
    volatile uint32_t SSCGR; /**< Spread spectrum clock generation register */
    volatile uint32_t PLLI2SCFGR; /**< PLLI2S configuration register */
    volatile uint32_t PLLSAICFGR; /**< PLLSAI configuration register */
    volatile uint32_t DCKCFGR; /**< Dedicated clocks configuration register */
    volatile uint32_t CKGATENR; /**< Clocks gated enable register */
    volatile uint32_t DCKCFGR2; /**< Dedicated clocks configuration register 2 */
} RCC_t;

/**
 * @brief Static assertions to ensure correct offsets of RCC registers
 */
_Static_assert(offsetof(RCC_t, APB1RSTR)  == 0x20, "");
_Static_assert(offsetof(RCC_t, AHB1ENR)   == 0x30, "");
_Static_assert(offsetof(RCC_t, APB1ENR)   == 0x40, "");
_Static_assert(offsetof(RCC_t, AHB1LPENR) == 0x50, "");
_Static_assert(offsetof(RCC_t, APB1LPENR) == 0x60, "");
_Static_assert(offsetof(RCC_t, BDCR)      == 0x70, "");
_Static_assert(offsetof(RCC_t, SSCGR)     == 0x80, "");
_Static_assert(sizeof(RCC_t)              == 0x98, "");

/**
 * @brief RCC clock status enumeration
 */
typedef enum {
    RCC_CLK_OFF = 0x0,
    RCC_CLK_ON = 0x1
} rcc_status_t;

/**
 * @brief AHB1 clock port enumeration
 */
typedef enum {
    RCC_AHB1_GPIOA = 0UL,
    RCC_AHB1_GPIOB = 1UL,
    RCC_AHB1_GPIOC = 2UL,
    RCC_AHB1_GPIOD = 3UL,
    RCC_AHB1_GPIOE = 4UL,
    RCC_AHB1_GPIOF = 5UL,
    RCC_AHB1_GPIOG = 6UL,
    RCC_AHB1_GPIOH = 7UL,
    RCC_AHB1_CRC = 12UL,
    RCC_AHB1_BKPSRAM = 18UL,
    RCC_AHB1_DMA1 = 21UL,
    RCC_AHB1_DMA2 = 22UL,
    RCC_AHB1_OTGHS = 29UL,
    RCC_AHB1_OTGHSULPI = 30UL  
} ahb1_clock_port_t;

/**
 * @brief AHB2 clock port enumeration
 */
typedef enum {
    RCC_AHB2_DCMI = 0UL,
    RCC_AHB2_OTGFS = 7UL
} ahb2_clock_port_t;

/**
 * @brief AHB3 clock port enumeration
 */
typedef enum {
    RCC_AHB3_FMC = 0UL,
    RCC_AHB3_QSPI = 1UL
} ahb3_clock_port_t;

/**
 * @brief APB1 clock port enumeration
 */
typedef enum {
    RCC_APB1_TIM2 = 0UL,
    RCC_APB1_TIM3 = 1UL,
    RCC_APB1_TIM4 = 2UL,
    RCC_APB1_TIM5 = 3UL,
    RCC_APB1_TIM6 = 4UL,
    RCC_APB1_TIM7 = 5UL,
    RCC_APB1_TIM12 = 6UL,
    RCC_APB1_TIM13 = 7UL,
    RCC_APB1_TIM14 = 8UL,
    RCC_APB1_WWDG = 11UL,
    RCC_APB1_SPI2 = 14UL,
    RCC_APB1_SPI3 = 15UL,
    RCC_APB1_SPDIFRX = 16UL,
    RCC_APB1_USART2 = 17UL,
    RCC_APB1_USART3 = 18UL,
    RCC_APB1_UART4 = 19UL,
    RCC_APB1_UART5 = 20UL,
    RCC_APB1_I2C1 = 21UL,
    RCC_APB1_I2C2 = 22UL,
    RCC_APB1_I2C3 = 23UL,
    RCC_APB1_FMPI2C1 = 24UL,
    RCC_APB1_CAN1 = 25UL,
    RCC_APB1_CAN2 = 26UL,
    RCC_APB1_CEC = 27UL,
    RCC_APB1_PWR = 28UL,
    RCC_APB1_DAC = 29UL,       
} apb1_clock_port_t;

/**
 * @brief APB2 clock port enumeration
 */
typedef enum {
    RCC_APB2_TIM1 = 0UL,
    RCC_APB2_TIM8 = 1UL,
    RCC_APB2_USART1 = 4UL,
    RCC_APB2_USART6 = 5UL,
    RCC_APB2_ADC1 = 8UL,
    RCC_APB2_ADC2 = 9UL,
    RCC_APB2_ADC3 = 10UL,
    RCC_APB2_SDIO = 11UL,
    RCC_APB2_SPI1 = 12UL,
    RCC_APB2_SPI4 = 13UL,
    RCC_APB2_SYSCFG = 14UL,
    RCC_APB2_TIM9 = 16UL,
    RCC_APB2_TIM10 = 17UL,
    RCC_APB2_TIM11 = 18UL,
    RCC_APB2_SAI1 = 22UL,
} apb2_clock_port_t;

/**
 * @brief AHB1 Clock Enable Function
 * @param port AHB1 clock port
 * @param clock_status Clock status
 */
void rcc_ahb1_clock_enable(ahb1_clock_port_t port, rcc_status_t clock_status);

/**
 * @brief AHB2 Clock Enable Function
 * @param port AHB2 clock port
 * @param clock_status Clock status
 */
void rcc_ahb2_clock_enable(ahb2_clock_port_t port, rcc_status_t clock_status);

/**
 * @brief AHB3 Clock Enable Function
 * @param port AHB3 clock port
 * @param clock_status Clock status
 */
void rcc_ahb3_clock_enable(ahb3_clock_port_t port, rcc_status_t clock_status);

/**
 * @brief APB1 Clock Enable Function
 * @param port APB1 clock port
 * @param clock_status Clock status
 */
void rcc_apb1_clock_enable(apb1_clock_port_t port, rcc_status_t clock_status);

/**
 * @brief APB2 Clock Enable Function
 * @param port APB2 clock port
 * @param clock_status Clock status
 */
void rcc_apb2_clock_enable(apb2_clock_port_t port, rcc_status_t clock_status);

#endif /* RCC_DRIVER_H */