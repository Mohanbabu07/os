#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *file1, *file2;
char filename[100],c;
printf("enter the filename for reading");
scanf("%s",filename);
file1 = fopen(filename,"r");
if ( file1 == NULL )
{
printf("cannot open the file %s \n",filename);
exit(0);
}
printf("Enter the filename for writing");
scanf("%s",filename);
file2 = fopen(filename,"w");
if ( file2 == NULL )
{
printf("cannot open the file %s\n",filename);
exit(0);
}
c = fgetc(file1);
while ( c != EOF )
{
fputc(c,file2);
c = fgetc(file1);
}
printf("The contents are copied to file %s",filename);
fclose(file1);
fclose(file2);
return 0;
} 

