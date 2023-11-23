#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFFER_SIZE 3
typedef struct{
int buffer[BUFFER_SIZE];
int in, out;
int itemCount;
}Monitor;
Monitor monitor1;
void moni(){
  void produce(int item){
   if(monitor1.itemCount >= BUFFER_SIZE){
      printf("Buffer is full.Producer waits.\n");
      return;
   }
   monitor1.buffer[monitor1.in] = item;
   monitor1.in = (monitor1.in + 1) % BUFFER_SIZE;
   monitor1.itemCount++;
   printf("Producer produces item %d\n",item);
   }
   int consume(){
   if(monitor1.itemCount == 0){
     printf("Buffer is empty.Consumer waits\n");
     return -1;
   }
   int item = monitor1.buffer[monitor1.out];
   monitor1.out = (monitor1.out + 1) % BUFFER_SIZE;
   monitor1.itemCount--;
   printf("Consumer consume item %d\n",item);
   return item;
   }
   monitor1.in = 0;
   monitor1.out = 0;
   monitor1.itemCount = 0;
   int choice;
   while (1){
        printf("\n1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);
        switch (choice){
                case 1:
                if(monitor1.itemCount < BUFFER_SIZE){
                    int item;
                    printf("Enter the item to produce: ");
                    scanf("%d", &item);
                    produce(item);
                 } else {
                     printf("Buffer is full. Producer waits.\n");
                 }
                 break;
                case 2:
                 if(monitor1.itemCount > 0) {
                     int item = consume();
                     if (item == -1 ){
                         printf("Failed to consume item\n");
                     }
                   } else {
                       printf("Buffer is empty. Consumer waits");
                   }
                   break;
                 case 3:
                   exit(0);
                   printf("Exit");
                   break;
                 default:
                   printf("Invalid Choice");
         }
}
}
int main(){
   moni();
   return 0;
}
