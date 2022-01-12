#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
   int info;
   struct node *link;
};

struct node* start = NULL;

void push()
{
    int num;
   struct node *newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   printf("enter the number to push:");
   scanf("%d",&num);
   newNode->info = num;
   if(start == NULL)
      newNode->link = NULL;
   else
      newNode->link = start;
   start = newNode;
}

void pop()
{
   if(start == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct node *temp = start;
      printf("\nitem that got popped out: %d\n", temp->info);
      start = temp->link;
   }
}
void display()
{
   if(start == NULL)
      printf("\nStack is Empty\n");
   else{
      struct node *temp = start;
      while(temp->link != NULL){
	     printf("%d-->",temp->info);
	     temp = temp -> link;
      }
      printf("%d--->NULL",temp->info);
   }
}


void main()
{
   int choice;
   printf("\n:: Stack using Linked List ::\n");

   while(1){
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
        if(choice==1) push();
        else if(choice == 2) pop();
        else if(choice == 3) display();
        else if (choice ==4 ) exit(0);
        else {printf("\ninvalid choice , choose between 1 to 4\n");}


   }
}

