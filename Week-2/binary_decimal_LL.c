#include <stdio.h>
#include <stdlib.h>
void create();
int display();
struct node
{
 int data;
 struct node *next;
};
struct node *head=NULL,*x,*y,*z;
int main()
{
 int n,bit,i;
 printf("enter the number of bits in the binary number");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("\nenter a bit\n");
  scanf("%d",&bit);
  create(bit);
 }
 display();
}
void create(int value)
{
 struct node * new = (struct node *)malloc(sizeof(struct node));
 new->data = value;
 new->next=NULL;
 if(head == NULL)
  head = new;
 else
 {
  x=head;
  while(x->next != NULL)
  {
   x=x->next;
  }
  x->next=new;
 }
}
int display()
{
 int dec=0;
 if(head == NULL)
  printf("list is empty");
 else
  {
   for(x=head;x!=NULL;x=x->next)
   {
    printf("%d\t",x->data);
    dec=dec*2+x->data;
   }
   printf("\ndecimal equivalent = %d",dec);
  }
}