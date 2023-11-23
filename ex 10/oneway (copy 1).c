#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int pipefds[2];
    int returnstatus;
    int pid;
    char writemessages[2][20]={"Hi", "Hello"};
    char readmessage[20];
    returnstatus = pipe(pipefds);
    if(returnstatus == -1) {
       perror("Unable to create pipe\n");
       exit(1);
    }
    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }
     else {

        close(pipefds[0]); 
        for (int i = 0; i < 2; i++) {
            write(pipefds[1], writemessages[i], strlen(writemessages[i]) + 1);
            printf("Parent Process - Writing to pipe - Message %d is %s\n",i + 1, writemessages[i]);
        }
        close(pipefds[1]);
       }
       return 0;

} 