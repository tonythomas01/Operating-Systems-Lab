/**
 * @author Tony Thomas <01tonythomas@gmail.com>
 * Program to show attributes of a file
 **/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define PERMS 0777 /* RW for owner, group, others */
char buffer[2048];

main(int argc, char *argv[] ) {
  int file;
	if (argc != 2 ) {
		printf("need 1 arguments to show attributes \n"); 
		exit(1);
	}
	struct stat *stat_buf;
	file = stat( argv[1], stat_buf );
	
	exit(0);
}
