#include<stdio.h>
#include<conio.h>
#include<string.h>
int top=-1;
char stack[13];
void push(char x)
{
top=top+1;
stack[top]=x;

}
void pop(char t)
{
if(t=='}')
{

if(stack[top]=='{')
top=top-1;
}
else if(t==')'){

if(stack[top]=='(')
top=top-1;
}
else if(t==']'){

if(stack[top]=='[')
top=top-1;
}

}
void display()
{
int i;
if(top==-1)
printf("stack is empty\nTherefore your input is balanced ");
else
printf("the input you have given is not balanced");
}

void main()
{
char input[100],x,t;
int k,i;

scanf("%s",input);
printf("ur input is %s",input);
k=strlen(input);
printf("\nthe length of input is %d\n",k);
for(i=0;i<k;i++)
{
if((input[i]=='{')||(input[i]=='(')||(input[i]=='['))
       {
         x=input[i];
         push(x);

       }
else if((input[i]=='}')||(input[i]==')')||(input[i]==']'))
    {
       t=input[i];
        pop(t);
    }
}
display();
getch();

}
