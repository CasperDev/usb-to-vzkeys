/*
 * uart_ring_buffer.h
 *
 *  Created on: Jun 1, 2021
 *      Author: ab
 */

#ifndef INC_UART_RING_BUFFER_H_
#define INC_UART_RING_BUFFER_H_

#include "stdint.h"

#define UART_BUFFER_SIZE 64

/* ring_buffer object */
typedef struct {
	uint8_t buffer[UART_BUFFER_SIZE];
	volatile uint32_t head;
	volatile uint32_t tail;

} RingBuf;


// Initialize ring_buffer
void RingBuf_Init(void);

//int RingBuf_HasData(void);



#endif /* INC_UART_RING_BUFFER_H_ */
