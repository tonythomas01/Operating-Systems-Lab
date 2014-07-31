#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define PERMS 0666 /* RW for owner, group, others */
char buffer[2048];

main(int argc, char *argv[] ) {
  int fdold, fdnew;
	if (argc != 3) {
		printf("need 2 arguments for copy program\n"); 
		exit(1);
	}
	fdold = open(argv[1],O_RDONLY); /* open source file in read only */
	if (fdold == -1) {
		printf("cannot open file %s\n",argv[1]);  
		exit(1);
	}
	int checkExist;
	checkExist = open( argv[2], O_APPEND | O_RDWR );
	if ( checkExist == -1 ) {
	  printf( " The file do not exists " );
	  fdnew = creat(argv[2],PERMS);
	  copy( fdold,  fdnew );
	  exit(1);
	  
	} else {
	  //suppose the file exists
	  printf( " The file exists " );
	  copy(fdold, checkExist );
	  exit(1);
	}
	exit(0);
}

copy(int old, int new ) {
	int count;
	while ((count = read(old,buffer,sizeof(buffer))) > 0)
		write(new,buffer,count);
}