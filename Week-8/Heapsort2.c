#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
int A[MAX]={};
int boolean;
int count=0;

void swap(int *x, int *y);
void print(int array[],int n);


void minheapify(int A[], int n, int i)
{

  int smallest = i;
  int l = (2 * i) + 1;
  int r = (2 * i)+ 2;

  if (l < n && A[l] < A[smallest])
  {
  	 smallest = l;
  }


  if (r < n && A[r] < A[smallest])
  {
  	 smallest = r;
  }


    if (smallest != i)
	{
      swap(&A[i], &A[smallest]);
      minheapify(A, n, smallest);
  	}
}



void maxheapify(int A[], int n, int i)
{
  int largest = i;
  int l = (2*i) +1;
  int r = (2*i)+2;

  if (l < n && A[l] > A[largest])
 	{
	 	largest = l;
	}

  if (r < n && A[r] > A[largest])
  {
  	    largest = r;
  }

    if (largest != i)
	{
      swap(&A[i], &A[largest]);
      maxheapify(A, n, largest);
  	}
}



void insert()
{
	int key,i,j,n;
	printf("\n Enter value to insert : ");
	scanf("%d",&key);
	n=count;
	A[n]=key;
	count++;
	n++;
	if(boolean==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	maxheapify(A, n, i);
		}
	}
	else if(boolean==2)
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	minheapify(A, n, i);
		}
	}

}


void buildheap()
{
	int n,size,i;
	printf("\n Enter number of elements : ");
	scanf("%d",&n);
	count = n;
	printf("\n Enter the elements into array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}

	if(boolean==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	maxheapify(A, n, i);
		}
	}
	else if (boolean == 2)
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	minheapify(A, n, i);
		}

	}
	print(A,n);
}




void Heapsort()
{
	int i,j,n;
	n=count;
	int array[n];
	for(i=0;i<n;i++)
	{
		array[i]=A[i];
	}
	    // Heap sort

	if(boolean==1)
	{
		for (i = n - 1; i >= 0; i--)
		{
	      swap(&array[0], &array[i]);


	      maxheapify(array, i, 0);
	    }
	}
	else
	{

		for (i = n - 1; i >= 0; i--)
		{
	      swap(&array[0], &array[i]);


	      minheapify(array, i, 0);
	    }

	}
    print(array,n);
}


void delete()
{
	int i,j,key,n,index,k=0;
	printf("\n value to be deleted: ");
	scanf("%d",&key);
	n=count;
	for(i=0;i<n;i++)
	{
		if(A[i]==key)
		{
			k=1;
			index=i;
			break;
		}
	}
	if(k==0)
	{
		printf("\n no such element is present in Array \n\n");
		return;
	}
	swap(&A[index],&A[n-1]);
	A[n-1]=0;
	count--;
	n--;
	printf("Found in index place %d and Deleted successfully",i);
	printf("\n");
	if(boolean==1)
	{
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	maxheapify(A, n, i);
		}
	}
	else
	{
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	minheapify(A, n, i);
		}
	}
}


void swap(int *x, int *y)
{
	int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void print(int array[],int n)
{
	int i;
	printf("\n array elements are: ");
	for(i=0;i<n;i++)
	{
		printf("  %d",array[i]);
	}
	printf("\n\n");
}




void main()
{
	int i,option,choose,built=0,val;
	printf("\n1.Using max-heapify\n2.Using min-heapify\nEnter Your choice\n");
	val = scanf("%d",&option);

	if(val!=1)
	{
		printf("\n not a valid choice \n");
		exit(0);
	}
	if(option==1 || option==2)
	{
		boolean=option;
		while(1)
		{
			if(option==1)
			{
				printf("\n HeapSort using MaxHeapify \n");
			}
			else if (option == 2)
			{
				printf("\n HeapSort using MinHeapify\n");
			}
			printf("\n1.Building heap by inserting integers\n2.insertion\n3.Delete Function\n4.Sort Function\n5.Exit\nEnter Your choice\n");
            scanf("%d",&choose);
			if(choose == 1)
			{
				if(built==0)
				{
					buildheap();
					built=1;
				}
				else
				{
					break;
				}
			}
			else if(choose == 2)
			{
				if(built==0)
				{
					printf("Heap is not built yet, Building heap\n");
					buildheap();
					built=1;

				}
				else
				{
					insert();
				}
			}
			else if(choose==3)
			{
				//delete
				if(built==0)
				{
					printf("Heap is not built yet, Building heap\n");
					buildheap();
					built=1;

				}
				else
				{
					delete();
				}

			}
			else if(choose==4)
			{
				//sort function
				if(built==0)
				{
					printf("Heap is not built yet, Building heap\n");
					buildheap();
					built=1;

				}
				else
				{
					Heapsort();
				}
			}
			else if(choose==5)
			{
				break;
			}
			else
			{
				printf("\nselect integers between 1 to 5\n");
			}
		}
	}
	else
		return;


}
