#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];

int front  = -1;
int rear   = -1;  // initially the queue will be empty 

void IsEmpty()    // to check whether queue is empty or not
{
    if(front==-1&rear==-1)              // return 1;                   
       printf("queue is empty\n");
    else                                // return 0;      
       printf("queue is not empty\n");
}
 
void IsFull()
{
    if(rear==size-1)                  // return 1;                  
       printf("queue is full\n");
    else                               // return 0;                   
       printf("queue is not full\n");
}
//will add the element at the rear end of the queue

void Enqueue()
{
    int value;
    printf("enter the value to add at end: enqueue\n");
    scanf("%d",&value);
   if(rear==size-1)
       printf("Queue is Full\n");
   else
   {
       arr[rear] = value;
       rear++;
   }
}

//removes the front element from the queue

void Dequeue()
{
   if(front==-1&rear==-1)
       printf("Queue is Empty.\n");
   else
   {
       printf("Dequeued element = %d\n",arr[front]);
    front++;
   }
}

void Display()
{
    int i;
    if(front==-1&rear==-1)
      printf("Queue is Empty.\n");
    else{
        for(i=front;i<=rear-1;i++)
        {
          printf("%d",arr[i]);
          printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    int choice;
   printf("\n:: Queue using Array ::\n");

   while(1){
      printf("1. IsEmpty\n2. IsFull\n3. Enqueue\n4. Dequeue\n5. Display\n6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
        if(choice==1) IsEmpty();
        else if(choice == 2) IsFull();
        else if(choice == 3) Enqueue();
        else if(choice == 4) Dequeue();
        else if(choice == 5) Display();
        else if (choice ==6 ) exit(0);
        else {printf("\ninvalid choice , choose between 1 to 6\n");}


   }
}