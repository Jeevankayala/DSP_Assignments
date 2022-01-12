#include <stdio.h>
#include<stdlib.h>
#define SIZE 100
int A[SIZE];  // array  to store the stack
int top = -1;    // variable top is used to point the top of the stack
int ele;
// Push operation to insert an element on top of stack.
void Push()
{
 printf(" Enter a value to be push:");
 scanf("%d",&ele);
  if(top == SIZE-1)
		printf(" stack is full : overflow\n");
  else
	A[++top] = ele;
}
// Pop operation to remove an element from top of stack.
void Pop()
{
	if(top == -1)
		printf(" No element to pop: Underflow\n");
    else {
        ele = A[top];
        printf("element that got popped out is %d\n",ele);
        top--;
         }
}
// Display operation to return elements in stack.
int Display()
{
   int i;
	printf("Stack: ");
	for(i = 0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");

}

// This function will return 1 (true) if stack is empty, 0 (false) otherwise
int IsEmpty()
{
    if(top == -1)
	   printf("stack is empty\n");
	else
	   printf("stack is not empty\n");
}

int main() {
	int choose;
	while(1) {
		printf("\t1  to push\n");
        printf("\t2  to pop\n");
        printf("\t3  to display the stack\n");
        printf("\t4  to find whether stack is empty\n");
        printf("\t5  to exit\n");
		printf("\n   choose anyone: ");
		scanf("%d",&choose);

		 if(choose==1) Push();
        else if(choose == 2) Pop();
        else if(choose == 3) Display();
        else if (choose ==4 ) IsEmpty();
        else if(choose==5) exit(1);
        else {printf("\ninvalid choose , choose between 1 to 4\n");}

	}

}
