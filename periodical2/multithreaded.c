/**
 *Write a multithreaded  program which does the followingOne thread adds up to a number given
 *E.g. given number 5, the thread should return 15 (1+2+3+4+5)Another  thread  adds up as following.
 *Given number 5 the thread should return 53 (1+2^2+3^2+4^2+5^2)
 *Use the induction formula n(n+1)(2n+1)/6
 *
 **/
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<pthread.h>
#define NUM_THREADS 2

void *findSum( void *arg ) {
	int num = *(( int* )arg ); 
	int i, sum = 0;
	for ( i= num; i >= 0; i-- ) {
		sum += i;
	}
	printf( "The sum of the digits till %d is %d ", num, sum );
}

void *finformSum( void *arg ) {
	int num = *(( int* )arg );
	int i, sum = 0;
	int k = num+1;
	int l = ( num*2 ) + 1;
	sum = (num*k*l)/6;
	printf( "The pattern sum is %d ", sum );
}

main() {
	pthread_t tid[NUM_THREADS];
	int i,n;
	printf ("Enter the number : " );
	scanf ( "%d", &n );
	pthread_create( &tid[0], NULL, findSum, &n  );
	pthread_create( &tid[1], NULL, finformSum, &n );
	for ( i = 0; i< NUM_THREADS; i++ ) {
		pthread_join( tid[i], NULL );
	}
}