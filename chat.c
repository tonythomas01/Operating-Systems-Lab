#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main() {
    int fd[2];
    int fdtwo[2];
    pid_t childid;

    pipe( fdtwo );
    pipe(fd);

    char writeString[10];
    char childString[10];

    childid = fork();
    while(1) {
        if( childid == 0 ) {
            //child
            close( fd[1] );
            read( fd[0], writeString, 10);
            printf( "Child: The recieved string is %s", writeString );

            printf(" \n Child > " );
            scanf( "%s", &childString );
            write( fdtwo[1], childString, 10 );

        } else {
            //parent
            close( fd[0] );
            printf( "\n Parent> ");
            scanf( "%s" , &writeString );
            write( fd[1], writeString, 10);

            read( fdtwo[0], childString, 10 );
            printf( "Parent: recieved  string is %s", childString );
        }
    }
}
