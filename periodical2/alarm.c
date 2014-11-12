// Write a program where the user gives input  in a loop, how many  seconds an alarm should be generated,
// the signal handler for the alarm should print “%d BEEP---- ALARM  GENERATED”,  When the user  inputs EXIT.
// The alarm should be removed when the program exits. 
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
handleAlarm( int d ) {
	char buff[10];
	printf( "\n %dBEEP---- ALARM  GENERATED \n ", d );
	printf( " Type EXIT to exit " );
	scanf( "%s", &buff );
	if ( strcmp( "EXIT", buff) == 0 ) {
		printf ( "\nCaught EXIT\n" );
		exit( 1 );
	}
}

main() {
	unsigned int seconds = 3;
	for( ;; ) {
		printf( "Enter size " );
		scanf( "%d", &seconds );
		signal( SIGALRM, handleAlarm(seconds) );
		alarm( seconds  );
		sleep( 1 );
	}
}