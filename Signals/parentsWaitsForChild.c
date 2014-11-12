#include <signal.h>
#include<stdio.h>
#include<stdlib.h>


killCatcher() {
	printf( "\nThe process with PID %d  is killed\n", getpid() );
	sleep ( 3 );
	exit( 1 );
}

main() {
	signal( SIGINT, killCatcher );
	printf( "\nThe parent PID is  %d\n", getpid() );
	
	if ( fork() == 0 ) {
		// in child process 
		for ( ;; );
	}
	for ( ;; );
}