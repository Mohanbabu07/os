#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
int pid, pid1,pid2;
pid = fork();
if ( pid == -1 )
{
 printf ("ERROR IN PROCESS CREATION\n");
exit(1);
}
if ( pid != 0)
{
pid1 = getpid();
printf("\n The Parent process ID is %d\n",pid1);
}
else
{
pid2 = getpid();
printf("\n The child Process ID is %d\n",pid2);
}
}
