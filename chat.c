#include<stdio.h>
#include<unistd.h> 
#include<sys/types.h>
#include<string.h>

int main() {
	int fd[2], fdn[2], n;
	pid_t childpid; 
	pipe( fd ); 
	pipe( fdn );
	char input[50];
	char quit[10] = "quit";
	char inputParent[50];
	char buffer[50];
	char bufferp[50];
	childpid = fork();
	if( childpid == -1) { 
		perror("fork");
		exit(1); 
	}
	while( 1 ) {
		if (childpid == 0) {
			close( fd[0] );
			
			scanf( "%s", &input );
			if( strcmp( quit, input ) == 0 ) {
				exit(1);
			}
			write( fd[1], input, (strlen(input)+1) );

			n  =  read(fdn[0], bufferp, sizeof( bufferp ) );
			printf("Child says : %s\n", bufferp );
			
		} else {
			close( fd[1] );
			n = read(fd[0], buffer, sizeof( buffer ) );
			printf("Received string: %s\n", buffer);
			
			scanf( "%s", &inputParent );
			write( fdn[1], inputParent, (strlen(inputParent)+1) );
			sleep(1);
		}
	}
}
