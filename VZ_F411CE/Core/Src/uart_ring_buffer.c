/*
 * uart_ring_buffer.c
 *
 *  Created on: Jun 1, 2021
 *      Author: ab
 */

#include "uart_ring_buffer.h"


RingBuf rx_buffer = {{0},0,0};
RingBuf tx_buffer = {{0},0,0};

RingBuf* _rx_buffer;
RingBuf* _tx_buffer;


void put_char(char c, RingBuf *buffer)
{
	int i = (buffer->head + 1) % UART_BUFFER_SIZE;
	// if we should be storing the received character into the location
	// just before the tail (meaning that the head would advance to the
	// current location of the tail), we're about to overflow the buffer
	// and so we don't write the character or advance the head.
	if (i != buffer->tail) {
	    buffer->buffer[buffer->head] = c;
	    buffer->head = i;
	}
}

void RingBuf_Init(void)
{
	_rx_buffer = &rx_buffer;
	_tx_buffer = &tx_buffer;
}
/*
int RingBuf_HasData(void)
{
	return (int)((UART_BUFFER_SIZE+_rx_buffer->head - _rx_buffer) % UART_BUFFER_SIZE);
}
*/
