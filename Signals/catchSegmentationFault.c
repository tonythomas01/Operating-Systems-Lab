/* signal : trap an illegal address reference */

#include <stdio.h>	
#include <stdlib.h>	
#include <signal.h>	/* defines signals and the signal() function */

sigsegvcatch() {
	printf( " Got a signal signum " );
	exit(1);
}

main(int argc, char **argv) {
	signal(SIGSEGV,sigsegvcatch); 
	
	int a;

	/* catch SIGSEGV - segmentation violation */
	/* Use the signal system call to catch the SIGSEGV signal here. */
	
	
	a = *(int *)0;	/* read address 0 */
}
