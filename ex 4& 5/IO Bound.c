#include<stdio.h>
#include<time.h>
void main()
{
clock_t start,end;
double runTime;
start =clock();
int i, num=1, primes=0;
int a;
printf("Enter range:");
scanf("%d",&a);
while(num <=a)
{
i=2;
while(i<=num)
{
if(num%i==0)
break;
i++;
}
if(i==num)
primes++;
system("clear");
printf("%d primes number \n",primes);
num++;
}
end=clock();
runTime =(end-start)/(double) CLOCKS_PER_SEC;
printf("This machine calculated all %d prime numbers under 1000 in %g seconds
\n",primes,runTime);}