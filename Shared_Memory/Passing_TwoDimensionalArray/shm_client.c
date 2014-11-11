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
	int k =0,i,j = 0;;

	int *array, *value;
	int convertedArray[50];
	
	/*
	 * We need to get the segment named
	 * "5678", created by the server.
	 */

	key = 5678;

	/*
	 * Locate the segment.
	 */

	shmid = shmget(key, LEN * sizeof(int), 0666 );

	/*
	 * Now we attach the segment to our data space.
	 */
	array = shmat(shmid, NULL, 0);
	
	int sizeSHMm = array[0];
	int sizeSHMn = array[1];
	int totalSizeSHM = sizeSHMm * sizeSHMn;
	
	printf( "The size of the SHM is %d\n", totalSizeSHM );
	for( i = 0, j = 2; i < totalSizeSHM; i++, j++ ) {
		convertedArray[i] = array[j];
	}
	
	int *arrayptr = convertedArray;

	// Print as a 2-D array 
	for ( i=0; i<sizeSHMm; i++ ) {
		printf( "\n" );
		for( j=0; j<sizeSHMn; j++ ) {
			printf( "%d ", *arrayptr++ );
		}
	}
	shmdt( array );
	exit(0);
}
