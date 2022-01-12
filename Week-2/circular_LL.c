#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char info[5][50];
	struct node* link;
}*head,*tail;

void display(){
	int x=1,check=0;

	struct node* temp;
	temp=head;
	while(temp!= head ||x==1){
		printf("%d. %s   %s  %s\n",x,temp->info[0],temp->info[1],temp->info[2]);
		temp=temp->link;
			x++;
	}
	temp=head;
	x=1;
	while(temp!=head || x==1){
		x=2;
	if(strcmp(temp->info[2],temp->link->info[0])){
		check=1;
		break;
	}
	
	temp=temp->link;
}
if(check==0)
printf("String matching\n");
else
printf("String not matching\n");	
}

void secondstring(){
	int x=1;
	struct node* temp;
	temp=head;
	while(temp!= head ||x==1){
		printf("%d. %s\n",x,temp->info[1]);
		temp=temp->link;
			x++;;
	}
	
}

void replace(int x){
	int y;
	printf("Enter the node from 1 to %d",x);
	if(scanf("%d",&y)==1){
	if(y>0 && y<= x){
		struct node* temp;
	temp=head;
	int i=1;
	while(i<y){
	temp=temp->link;
	i++;
}
	printf("Enter the position of the string to be replaced (1 to 3): ");
	scanf("%d",&y);
	if(y>=0 && y<=3){
	printf("Enter the string\n");
	scanf("%s",&temp->info[y-1]);
	printf("String replaced successfully\n");
}
else
printf("Invalid position\n");
}
else
printf("Invalid node\n");
}
else{
	printf("Error occured");
	exit(0);
}
}

int main(){
    int x;
	printf("Enter no. of nodes: ");
	if(scanf("%d",&x) ==1){
	for(int i=1;i<x+1;i++){
	printf("Enter the 3 strings in %d node of linked list\n",i);
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	for(int p=0;p<3;p++)
	scanf("%s",&temp->info[p]);
	if(head==NULL && tail==NULL){
		temp->link=NULL;
		head=temp;
		tail=temp;
	}
	else{
		tail->link=temp;
		tail=temp;
		tail->link=head;
	}
}
int choice;
while(1){
printf("Enter the choice\n1.Display all %d nodes \n2.Display Second String of all nodes \n3.Replace String values \n4.Exit \n",x);
scanf("%d",&choice);

if(choice==1)
display();
else if(choice==2)
secondstring();
else if(choice==3)
replace(x);
else if(choice==4)
exit(0);
else{
printf("Invalid choice\n");
exit(0);
}
}
}
}