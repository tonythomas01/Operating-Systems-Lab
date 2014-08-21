#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>

int main(int argc, char* argv[] ) 
{
	int fd[2];
	pid_t childpid; 
	pipe( fd ); 
	if((childpid = fork()) == -1) 
	{ 
		perror("fork");
		exit(1); 
	}
	if (childpid == 0) 
	{ 
		/* Child process closes up input side of pipe */ 
		close(fd[0]);
		dup2( fd[1], 1 );
		/* Send "string" through the output side of pipe */ 	
		execlp( argv[1], argv[1], NULL );
	} 
	else
	{
		/* Parent process closes up output side of pipe */
		close(fd[1]);
		dup2( fd[0], 0 );
		execlp( argv[2], argv[2], NULL );
	}
	return(0); 
}


