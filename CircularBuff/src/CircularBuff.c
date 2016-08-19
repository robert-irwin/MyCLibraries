/*
 * CircularBuff.c
 *
 *  Created on: Jun 13, 2016
 *      Author: robertirwin
 */

#include	"CircularBuff.h"
#include	<stdlib.h>
#include	<stdint.h>
/* Name: 		CircBuffInit
 *
 * Description: Initializes a circular buffer with number of elements
 * 				defined by 'capacity + 1' where each element is type 'int'.
 */
void CircBuffInit(CircularBuff *cb, int capacity)
{
	cb->buffer = malloc((capacity + 1) * sizeof(uint16_t));
	cb->buffend = cb->buffer + (capacity);
	cb->buffbegin = cb->buffer;
	cb->headptr = cb->buffer;
	cb->tailptr = cb->buffer;
	cb->capacity = capacity;
	cb->count = 0;
}

/* Name: 		CircBuffPut
 * Description: Inserts data pointed to 'val' to the buffer at the point currently
 * 				marked by the 'headptr' variable.
 */
void CircBuffPut(CircularBuff *cb, uint16_t * val)
{
	*(cb->headptr) = *val;
	if (cb->headptr == cb->buffend)
	{
		cb->headptr = cb->buffbegin;
	}
	else (cb->headptr)++;

	if (cb->count < cb->capacity)
	{
		(cb->count)++;
	}
}


/* Name:		CircBuffGet
 * Description: Takes an int pointer, 'tail', and stores
 * 				the current value of the tail of the circular
 * 				buffer 'cb' into the input argument 'tail'.
 */
void CircBuffGet(CircularBuff *cb, uint16_t * tail)
{
	*tail = *(cb->tailptr);
	if (cb->tailptr == cb->buffend)
	{
		cb->tailptr = cb->buffbegin;
	}
	else (cb->tailptr)++;
}
