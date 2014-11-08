#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27


main()
{

	char c;
	int shmid;
	key_t key;
	int *shm, *s;
	int *array, value;



	/*
	 * We'll name our shared memory segment
	 * "5678".
	 */

	key = 5678;


	/*
	 * Create the segment.
	 */

	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}


	/*
	 * Now we attach the segment to our data space.
	 */

	if ((array = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}



	/*
	 * Now put some things into the memory for the
	 * other process to read.
	 */
	
	int i,j,m,n,k=0;

	printf( " Enter the order of the values you need to insert m : " );
	scanf( "%d" , &m );

	for ( i=0; i<m; i++ ) {
		printf( "Enter the value to insert :");
		scanf( "%d", array++ );
	}
	array[++i] = -1;
	

	/*
	 * Finally, we wait until the other process 
	 * changes the first character of our memory
	 * to '*', indicating that it has read what 
	 * we put there.
	 */
	shmdt( array );
	
	exit(0);
}
