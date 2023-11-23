#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_SIZE 3
int buffer[BUFFER_SIZE];
int count = 0;
int turn = 0;
void producer_consumer(){
  int item = 1;
  while (1) {
     if(turn == 0){
       if(count<BUFFER_SIZE){
          buffer[count] = item;
          count++;
          printf("Produced: %d\n",item);
          item++;
        }else{
          printf("Buffer is full\n");
          turn = 1;
        }
      }else{
        if(count > 0){
           int consumed_item = buffer[count -1];
           count--;
           printf("Consumed: %d\n",consumed_item);
        }else{
           printf("Buffer is Empty\n");
           turn = 0;
           exit(0);
       }
     }
   } 
 }
int main(){
   int n;
   pid_t producer_consumer_pid;
   producer_consumer_pid = fork();
   if(producer_consumer_pid < 0){
     perror("Forking producer-consumer process failed");
     exit(1);
   }
   if(producer_consumer_pid == 0){
      producer_consumer();
   }else{
     wait(NULL);
}
return 0;
}
