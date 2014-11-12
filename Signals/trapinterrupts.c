#include <signal.h>
#include<stdio.h>
#include<stdlib.h>

void cnt(int sig); 
void cnt1(int sig);
void cnt1again();

void cnt( int sig ) {
	printf( "\n Clicked Ctrl + C\n" );

}

void cnt1( int sig ) {
	printf( "\nClicked Ctrl+ Z, press the same again to exit\n" );
	signal(SIGTSTP, cnt1again ); 
}

void cnt1again() {
	printf( "\nExiting\n" );
	exit(1);
}
main() {  
	signal(SIGINT, cnt);    
	signal(SIGTSTP, cnt1);    /* SIGTSTP = cntl-Z */

	printf( "Begin counting INTERRUPTs and cntl-Z \n" ); 
	for(;;);  /* infinite loop */ 

} 
