/**
 * @file usart_driver.h
 * @brief USART driver header file
 * 
 * This file contains the definitions and declarations for the USART driver.
 * It defines the USART register structure, base addresses for USART peripherals,
 * and static assertions to ensure correct memory layout.
 */
#ifndef USART_DRIVER_H
#define USART_DRIVER_H

#include <stdint.h>
#include <stddef.h> 

/**
 * @brief USART Register structure definition
 */
typedef struct{
    volatile uint32_t SR; /**< Status register */
    volatile uint32_t DR; /**< Data register */
    volatile uint32_t BRR; /**< Baud rate register */
    volatile uint32_t CR1; /**< Control register 1 */
    volatile uint32_t CR2; /**< Control register 2 */
    volatile uint32_t CR3; /**< Control register 3 */
    volatile uint32_t GTPR; /**< Guard time and prescaler register */
} USART_t;

/** 
 * @brief Static assertions to ensure correct memory layout of struct 
 */
_Static_assert(offsetof(USART_t, SR)   == 0x00, "SR offset");
_Static_assert(offsetof(USART_t, DR)   == 0x04, "DR offset");
_Static_assert(offsetof(USART_t, BRR)  == 0x08, "BRR offset");
_Static_assert(offsetof(USART_t, CR1)  == 0x0C, "CR1 offset");
_Static_assert(offsetof(USART_t, CR2)  == 0x10, "CR2 offset");
_Static_assert(offsetof(USART_t, CR3)  == 0x14, "CR3 offset");
_Static_assert(offsetof(USART_t, GTPR) == 0x18, "GTPR offset");
_Static_assert(sizeof(USART_t) == 0x1C, "USART_t size");

/**
 * @brief USART base addresses for STM32F4xx series microcontrollers
 */
#define USART1 ((USART_t *)0x40011000UL)
#define USART2 ((USART_t *)0x40004400UL)
#define USART3 ((USART_t *)0x40004800UL)
#define UART4  ((USART_t *)0x40004C00UL)
#define UART5  ((USART_t *)0x40005000UL)
#define USART6 ((USART_t *)0x40011400UL)

#endif /* USART_DRIVER_H */