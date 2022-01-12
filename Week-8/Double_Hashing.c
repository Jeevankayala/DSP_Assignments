#include<stdio.h>
#include<stdlib.h>
int Total_Values = 0;
int *arr=NULL;

void insert(int n,int no)
{
    int key,i,j=0;
    int h1 = no % n;
    int h2 = 8-(no%8);

    for( i=0;i<n;i++)
    {
     key=(h1+i*h2)%n;
     if(arr[key] == -1)
     {
        arr[key]=no;
        Total_Values = Total_Values + 1;
         break;
     }
    if(i == n)
     printf("\n HashTable is full, cannot insert\n");
  }
}

void search(int n,int s)
{
    int key1,i;
    int key = s % n;

    for(i=0;i<n; i++)
 {
    key1=(key+i)%n;
    if(arr[key1]==s)
    {
      printf("Search Found at Position : %d \n",key1);
      break;
    }
  }
  if(i == n)
    printf("Search Not Found\n");
}

void delete(int n,int val)
{
    int key1,i;
    int key = val % n;
    for(i=0;i<n; i++)
 {
    key1=(key+i)%n;
    if(arr[key1]==val)
    {
      arr[key1] = -1;
      Total_Values = Total_Values - 1;
      break;
    }
  }
  if(i == n)
    printf("%d not present in the hash table\n",val);

}

void print(int n)
{

  int i;
  printf("\nElements in the Hash table are :\n");
  for(i=0;i< n; i++)
  printf("\nAt index %d \t value =  %d",i,arr[i]);

}

int main()
{

    int n,i,choice;
    float Loadfactor;


	 printf("Enter Size of an Array:");
    scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
    {
        arr[i]=-1;
    }

    while(1)
    {
    printf("\nEnter Your Choice:\n 1. Inserting into hash table using Double hashing\n 2. Searching by value \n 3. Deletion\n 4. load factor of the hash table\n 5. Exit\n  ");
    if(scanf("%d",&choice)==1)
    {
    if(choice==1)
    {   int no;
        printf("Enter value to insert :");
        scanf("%d",&no);
        insert(n,no);
        print(n);

    }
    else if(choice==2)
    {   int s;
        printf("Enter value to serach : ");
        scanf("%d",&s);
        search(n,s);
    }
    else if(choice==3)
    {   int val;
        printf("Enter value to delete :");
        scanf("%d",&val);
        delete(n,val);
        print(n);

    }
    else if(choice==4)
    {
        Loadfactor = (float)Total_Values/(float)n;
        printf("\nTotal_Values:%d",Total_Values);
        printf("\nLoad Factor of the Hash table : %f ",Loadfactor);
    }
    else if(choice==5)
    {
        exit(0);
    }
    else{
        printf("Invalid choice!");
    }

    }
    else{
        printf("Enter Numbers from 1 to 5");
        exit(0);
    }
    }

}
