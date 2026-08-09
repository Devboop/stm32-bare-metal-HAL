/** @file rcc_driver.c
 *  @brief RCC driver implementation
 *  @author Dominick Green 
 */

#include "rcc_driver.h"

void rcc_ahb1_clock_enable(ahb1_clock_port_t port, rcc_status_t clock_status){
    switch (clock_status) {
        case RCC_CLK_ON: 
            RCC->AHB1ENR |= ((1UL) << (port));
            break;

        case RCC_CLK_OFF: 
            RCC->AHB1ENR &= ~((1UL) << (port));
            break;

        default: 
            RCC->AHB1ENR &= ~((1UL) << (port));
    }
}

void rcc_ahb2_clock_enable(ahb2_clock_port_t port, rcc_status_t clock_status){
    switch (clock_status) {
        case RCC_CLK_ON: 
            RCC->AHB2ENR |= ((1UL) << (port));
            break;

        case RCC_CLK_OFF: 
            RCC->AHB2ENR &= ~((1UL) << (port));
            break;

        default: 
            RCC->AHB2ENR &= ~((1UL) << (port));
    }
}

void rcc_ahb3_clock_enable(ahb3_clock_port_t port, rcc_status_t clock_status){
    switch (clock_status) {
        case RCC_CLK_ON: 
            RCC->AHB3ENR |= ((1UL) << (port));
            break;

        case RCC_CLK_OFF: 
            RCC->AHB3ENR &= ~((1UL) << (port));
            break;

        default: 
            RCC->AHB3ENR &= ~((1UL) << (port));
    }
}

void rcc_apb1_clock_enable(apb1_clock_port_t port, rcc_status_t clock_status){
    switch (clock_status) {
        case RCC_CLK_ON: 
            RCC->APB1ENR |= ((1UL) << (port));
            break;

        case RCC_CLK_OFF: 
            RCC->APB1ENR &= ~((1UL) << (port));
            break;

        default: 
            RCC->APB1ENR &= ~((1UL) << (port));
    }
}

void rcc_apb2_clock_enable(apb2_clock_port_t port, rcc_status_t clock_status){
    switch (clock_status) {
        case RCC_CLK_ON: 
            RCC->APB2ENR |= ((1UL) << (port));
            break;

        case RCC_CLK_OFF: 
            RCC->APB2ENR &= ~((1UL) << (port));
            break;

        default: 
            RCC->APB2ENR &= ~((1UL) << (port));
    }
}