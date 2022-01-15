#include<stdio.h>

int q[20],top=-1,front=-1,rear=-1,a[20][20],visited[20],stack[20],N,v;

void AdjacencyMatrix()            // Function to Create the Graph
{
    int i,j;
    printf("\nEnter No. of Vertices : ");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
    for(j=1;j<=N;j++)
    {
    printf("Press 0 if %d is not connected to %d if not 1 : ",i,j);
    scanf("%d",&a[i][j]);
    }
    }
    printf("Adjacency Matrix created by the above given connections between vertices : \n");
    for(i=1;i<=N;i++)
    {
    for(j=1;j<=N;j++)
    {
    printf(" %d",a[i][j]);
    }
    printf("\n");
    }

    for(i=1;i<=N;i++)
    visited[i]=0;

   printf("Enter the Starting Vertex : ");
    scanf("%d",&v);
    if(v<1||v>N)
      {
          printf("Invalid Starting Vertex");
          exit(1);
      }

}


//BFS(breadth-first search) Function
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
//bfs(i,n);
return ;
}


void add(int item)           // Add Function into Queue
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
int delete()                // Delete Function on Queue
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


//DFS(depth-first search) Function//
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
//dfs(i,n);
return ;
}

void push(int item)          // Push Function on Stack
{
if(top==19)
printf("Stack overflow ");
else
stack[++top]=item;
}

int pop()                   // Pop Function on Queue
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
int choice;


while(1)
  {
    int choice;
    printf("\n1.BFS Traversal\n2.DFS Traversal\n3.Exit\nENTER YOUR CHOICE : ");
    scanf("%d",&choice);

    while(1)
    {
    if(choice==3) exit(1);      // Exit Function placed to not Enter into AdjacencyMatrix Function

     AdjacencyMatrix();

    if(choice==1)
    {
     bfs(v,N);                 //  BFS Function call
     break;
    }

    else if(choice==2)
    {
     dfs(v,N);                //  DFS Function call
     break;
    }

    else printf("choose between 1 to 3 ");
    }
  }
}

