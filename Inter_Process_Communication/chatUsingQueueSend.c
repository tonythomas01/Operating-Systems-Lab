/**
 *Program to show InterProcess Communication
 * */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MSGSZ     128

/*
 * Declare the message structure.
 */
typedef struct msgbuf {
	long    mtype;
	char    mtext[MSGSZ];
} message_buf;

main()
{
	int msqid;
	int msgflg = IPC_CREAT | 0666;
	key_t key;

	char readBuffer[40];


	message_buf sbuf;
	message_buf rbuf;
	size_t buf_length;

	/*
	 * Get the message queue id for the
	 * "name" 1234, which was created by
	 * the server.
	 */

	key = 1234;
	while(1) {

		(void) fprintf(stderr, "\nmsgget: Calling msgget(%#lx,\
			%#o)\n",
				key, msgflg);


		if ((msqid = msgget(key, msgflg )) < 0) {
			perror("msgget");
			exit(1);
		}
		else 
			(void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);

		/*
		* We'll send message type 1
		*/
		
		printf(" Enter the message to send from P1 -----> P2: \n " );
		scanf( "%s", &readBuffer );

		sbuf.mtype = 1;
		(void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);
		(void) strcpy(sbuf.mtext, readBuffer );
		(void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);

		buf_length = strlen(sbuf.mtext) + 1 ;

		/*
		* Send a message.
		*/

		if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
			printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
			perror("msgsnd");
			exit(1);
		}
		else 
			printf("Message: \"%s\" Sent\n", sbuf.mtext);
		
		/**recieve from the other one
		*/
		if (msgrcv(msqid, &rbuf, MSGSZ, 2, 0) < 0) {
				perror("msgrcv");
				exit(1);
		}
		printf("Recieved from P2 :%s\n", rbuf.mtext);

	}
	exit(0);

}
