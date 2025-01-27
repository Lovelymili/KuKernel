#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

extern uint16_t original_ds;
extern uint16_t kernel_ds;

void isr_handler(void);

void isr_exit(void);

#endif