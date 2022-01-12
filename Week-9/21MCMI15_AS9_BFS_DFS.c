#include<stdio.h>

int q[20],top=-1,front=-1,rear=-1,a[20][20],visited[20],stack[20];








//BFS(breadth-first search) code
void bfs(int s,int n)
{
int p,i;
add(s);
visited[s]=1;
p=delete();
if(p!=0)
printf(" %d",p);
while(p!=0)
{
for(i=1;i<=n;i++)
if((a[p][i]!=0)&&(visited[i]==0))
{
add(i);
visited[i]=1;
}
p=delete();
if(p!=0)
printf(" %d ",p);
}
for(i=1;i<=n;i++)
if(visited[i]==0)
bfs(i,n);
}


void add(int item)
{
if(rear==19)
printf("QUEUE FULL");
else
{
if(rear==-1)
{
q[++rear]=item;
front++;
}
else
q[++rear]=item;
}
}
int delete()
{
int k;
if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}


//DFS(depth-first search) code//
void dfs(int s,int n)
{
int i,k;
push(s);
visited[s]=1;
k=pop();
if(k!=0)
printf(" %d ",k);
while(k!=0)
{
for(i=1;i<=n;i++)
if((a[k][i]!=0)&&(visited[i]==0))
{
push(i);
visited[i]=1;
}
k=pop();
if(k!=0)
printf(" %d ",k);
}
for(i=1;i<=n;i++)
if(visited[i]==0)
dfs(i,n);
}
void push(int item)
{
if(top==19)
printf("Stack overflow ");
else
stack[++top]=item;
}
int pop()
{
int k;
if(top==-1)
return(0);
else
{
k=stack[top--];
return(k);
}
}


void main()
{
int i,j,n,v,choice;
char s1,s2;
printf("Enter No. of Vertices : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("Press 0 if %d is not connected to %d if not 1 : ",i,j);
scanf("%d",&a[i][j]);
}
}
printf("Adjacency Matrix created by the above given connections between vertices : \n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf(" %d",a[i][j]);
}
printf("\n");
}

do
{
for(i=1;i<=n;i++)
visited[i]=0;

printf("\n1.BFS Traversal ");
printf("\n2.DFS Traversal ");
printf("\nEnter Your Choice : ");
scanf("%d",&choice);
printf("Enter the Starting Vertex : ");
scanf("%d",&v);

switch(choice)
{
case 1:bfs(v,n);
break;
case 2:dfs(v,n);
break;
}
printf("\n  Enter Y to continue and N to Exit (Y/N) ? ");
scanf("%c",&s1);
scanf("%c",&s2);
}while((s2=='y')||(s2=='Y'));
}


