/**
 *Program to show InterProcess Communication
 * */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

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
	key_t key;
	message_buf  rbuf;
	message_buf  sbuf;

	char readBuffer[40];
	size_t buf_length;

	/*
	 * Get the message queue id for the
	 * "name" 1234, which was created by
	 * the server.
	 */

	key = 1234;
	while(1) {
		if ((msqid = msgget(key, 0666)) < 0) {
			perror("msgget");
			exit(1);
		}
		printf( " Ready to recieve \n " );

		/*
		 * Receive an answer of message type 1.
		 */
		if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
			perror("msgrcv");
			exit(1);
		}

		/*
		 * Print the answer.
		 */
		printf("%s\n", rbuf.mtext);

		/**
		 * send the message through 2 outlet
		 */

		printf(" Enter the message to send from P2 -----> P1: \n " );
		scanf( "%s", &readBuffer );

		sbuf.mtype = 2;
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
	}
	exit(0);
}
