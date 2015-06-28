#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 50

int main( int argc, char* argv[] ) {
    int fdone[2];
    pid_t childid;

    char readBuff[BUFFER_SIZE];

    pipe(fdone);

    if( argc != 3 ) {
        printf("ERROR: Need exactly 2 parameters.\n");
        exit(1);
    }

    int fileOpen = open(argv[1], 0);
    int targetFile = open(argv[2], O_RDWR|O_CREAT|O_APPEND, 0666);

    if (fileOpen == -1 || targetFile == -1) {
        printf("ERROR: Opening file failed\n");
        exit(1);
    }
    childid = fork();

    if (childid == 0) {
        // inside the child prcocess
        close(fdone[1]);

        while (read(fdone[0], readBuff, sizeof(readBuff)) > 0) {
            // Writing to the target fileOpen
            write(targetFile, readBuff, strlen(readBuff) - 1);
        }

        close(fdone[0]);
        close(targetFile);
    }
    else {
        // inside the parent process
        close(fdone[0]);

        // code to read from a text file
        while (read(fileOpen, readBuff, sizeof(readBuff)) > 0) {
            write(fdone[1], readBuff, sizeof(readBuff));
            memset(readBuff, 0, BUFFER_SIZE);
        }

        close(fdone[1]);
        close(fileOpen);
        wait(NULL);
    }
}
