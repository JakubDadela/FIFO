



#include "pch.h"
#include "kolejka.h"
#include <iostream>

int main()
{
	Queue* v = Create( 15 );

	for( int i = 0; i < 15; i++ )
	{
		fInfo* w = (fInfo*)calloc( 1, sizeof( fInfo ) );
	/*	if( !w )
		{
			perror( "Bład alokacji" );
			return 0;
			
		}*/
		w->key = i+2;
		//printf( "%d ", w->key );
		Enqueue( v, w );
		printf( "%d ", v->tab[i]->key );
	}
	printf( "%d ", v->tab[v->head + 3]->key );
	fInfo* c = Dequeue( v );
	printf( "%d ", c->key );
	Remove( &v );
     
}
