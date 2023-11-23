#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char string1[]="Hello Mohan";
char string2[]="Welcome to KEC";
int main(void)
{
pid_t PID;
PID = fork();
if ( PID == 0 )
{
printf("%s",string1);

}

else
{
printf("%s",string2);
}
exit(0);
}

