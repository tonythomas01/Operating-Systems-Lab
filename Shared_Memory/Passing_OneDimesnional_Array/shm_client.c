#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27
#define LEN 5

main()
{

	int shmid;
	key_t key;
	int k =0;


	int *array, *value;

	/*
	 * We need to get the segment named
	 * "5678", created by the server.
	 */

	key = 5678;

	/*
	 * Locate the segment.
	 */

	if ((shmid = shmget(key, LEN * sizeof(int), 0666 )) < 0) {
		perror("shmget");
		exit(1);
	}



	/*
	 * Now we attach the segment to our data space.
	 */

	array = shmat(shmid, NULL, 0);
	if ( array == ( int * ) -1 ) {
		perror( "fail to attach " );
		exit(1);
	}

		for (k = 0; k < LEN; k++) {
			printf("%d\n", array[k] );
		}
	/*
	 * Now read what the server put in the memory.
	 */

	shmdt( array );


	/*
	 * Finally, change the first character of the 
	 * segment to '*', indicating we have read 
	 * the segment.
	 */

	exit(0);

}
