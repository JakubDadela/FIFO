#ifndef _FIFO_H
#define _FIFO_H

#include "Global.h"
#include <memory.h>
#include <cstdlib>

typedef struct{
	fInfo** tab;
	int head;
	int tail;
	int ile;
	int nSize;
}Queue;

Queue* Create( int Size ); 
int isEmpty( Queue *q ); 
void Enqueue( Queue* q, fInfo* Info ); 
fInfo* Dequeue( Queue* q ); 
void Clear( Queue* q ); 
void Remove( Queue** q );

#endif