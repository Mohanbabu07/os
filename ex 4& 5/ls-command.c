#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main()
{
char dirname[20];
DIR *p;
struct dirent *d;
printf("Enter the directory name");
scanf("%s",dirname);
p = opendir(dirname);
        if ( p == NULL )
        {
           printf("cannot find the directory");
           exit(-1);
        }
        while ( d = readdir(p) )
        { 
          printf("%s\n",d->d_name);
        }
}
