
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int childpid;
if ((childpid = fork()) == -1)
            {
                printf("\n can't fork");
                exit(1);
            }
else if(childpid == 0)
           {
                printf("\n Child: Child Pid=%d, Parent Pid=%d\n",getpid(),getppid());
                exit(0);
            }
else
            {
                printf("\n Parent: Child Pid=%d, Parent Pid=%d\n",childpid,getpid());
                exit(0);
            }
}
