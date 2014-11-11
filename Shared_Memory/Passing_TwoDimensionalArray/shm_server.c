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

	shmid = shmget(key, SHMSZ, IPC_CREAT | 0666 );

	/*
	 * Now we attach the segment to our data space.
	 */

	array = shmat(shmid, NULL, 0);


	/*
	 * Now put some things into the memory for the
	 * other process to read.
	 */
	
	int i,j,m,n,k=0;

	printf( " Enter the order of the matirx ( m * n ): " );
	scanf( "%d" , &m );
	scanf( "%d" , &n );
	
	*( array++ ) = m;
	*( array++ ) = n;

	for ( i=0; i<m; i++ ) {
		for( j=0; j<n; j++ ) {
			printf( "Enter the value to insert :");
			scanf( "%d", array++ );
		}
	}

	/*
	 * Finally, we wait until the other process 
	 * changes the first character of our memory
	 * to '*', indicating that it has read what 
	 * we put there.
	 */
	shmdt( array );
	
	exit(0);
}
