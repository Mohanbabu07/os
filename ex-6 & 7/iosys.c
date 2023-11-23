#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(){
int fd;
char buffer[50];
char msg[50]="Hello! Welcome to kec";
fd = open("sample1.txt",O_RDWR | O_CREAT,S_IRUSR | S_IWUSR);
printf("\nfd = %d\n",fd);
if ( fd != -1)
{
printf(" the write to read and write \n");
write(fd, msg, strlen(msg));
//seek(fd, O, SEEK_SET);
read(fd, buffer, sizeof(buffer));
printf("%s the content in the file\n",msg);
close(fd);
}
return 0;
}
