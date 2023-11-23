#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
FILE *file1;
char filename[100],search[10],temp[10];
int found = 0;
printf("ENTER THE FILENAME:");
scanf("%s",filename);
printf("Enter the element to be searched");
scanf("%s",search);
file1 = fopen(filename,"r");
while ( !feof(file1) )
         {
            fgets(temp,sizeof(file1),file1);
            if(strstr(temp,search))
                  {
                    printf("%s",temp);
                    found = 1;
                  }
         }
fclose(file1);
if(!found)
{
printf("THe searched word is Not in the file");
}
}
