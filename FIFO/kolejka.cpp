#include "pch.h"
#include "kolejka.h"

Queue* Create( int Size )
{
	Queue* w = (Queue*)calloc( 1,sizeof( Queue ) );
	if( !w )
	{
		perror( "B³ad alokacji(Create)" );
		return NULL;
	}
	w->tab= ( fInfo** )calloc( Size, sizeof( fInfo* ) );
	if( !(w->tab) )
	{
		free( w );
		perror( "B³ad alokacji(Create)" );
		return NULL;
	}
	w->nSize = Size;
	return w;
}


int isEmpty( Queue *q )
{
	return!( q->ile );

}
void Enqueue( Queue* q, fInfo* Info )
{
	if( q->ile == q->nSize ){
		perror( "Nie ma miejsca do dodania elementu" );
		return;
	}
		q->tab[q->tail] = Info;
		q->tail = (q->tail + 1) % q->nSize;
		
		q->ile++;
	
}
fInfo* Dequeue( Queue* q )
{
	if( isEmpty( q ) ){
		perror( "Kolejka jest pusta nie mozna nic odj¹æ" );
		return NULL;
	}
	fInfo* value = q->tab[q->head];
	q->tab[q->head]=NULL;
	q->head =( q->head + 1)% q->nSize;
	q->ile--;
	return value;

}
void Clear( Queue* q )
{
	if( !isEmpty( q ) )
	{
		for( int i = 0; i < q->nSize; i++ ){
			if( q->tab[i] )
				free( q->tab[i] );
		}
		q->head = 0;
		q->ile = 0;
		q->tail = 0;
		memset( q->tab, 0, sizeof( Queue ) );
	}
}
void Remove( Queue** q )
{
	Clear( *q );
	free( *q );
	*q = NULL;
}
