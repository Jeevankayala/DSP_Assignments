#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char Q[100][50];
int Pr[50];
int r = -1,f = -1;
int N;

void enqueue(char name[20],int G)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
        printf("Queue is full");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			strcpy(Q[r],name);
			Pr[r] = G;

		}
		else if(r == N-1)//if there there is some elements in Queue
		{
			for(i=f;i<=r;i++) {
                    strcpy(Q[i-f],Q[i]);
                    Pr[i-f] = Pr[i];
                    r = r-f; f = 0;
              for(i = r;i>f;i--)
				{
					if(G>Pr[i])
					{
						strcpy(Q[i+1],Q[i]);
						Pr[i+1] = Pr[i];
					}
					else
						break;
					strcpy(Q[i+1],name);
					Pr[i+1] = G;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(G>Pr[i])
				{
					strcpy(Q[i+1],Q[i]);
					Pr[i+1] = Pr[i];
				}
				else
					break;
			}
			strcpy(Q[i+1],name);
			Pr[i+1] = G;
			r++;
		}
	}

}
void print() //print the data of Queue
{
    if((f == -1)&& (r == -1))
	{
		printf("Queue is Empty");
	}
	else{
         int i;
        for(i=f;i<=r;i++)
	       printf("\nElement = %s\tPriority = %d",Q[i],Pr[i]);
	}
}
int dequeue() //remove the data from front
{
	 if((f == -1)&& (r == -1))
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("deleted Element = %s\t Its Priority = %d",Q[f],Pr[f]);
		printf("\n");
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}

int main()
{
    printf("Enter the size\n");
    scanf("%d",&N);
     enqueue("Jeevan",400);
     enqueue("Bunny",450);
     enqueue("Sunny",420);
     enqueue("Kenny",450);
     dequeue();
     enqueue("Benny",410);
     dequeue();


}
