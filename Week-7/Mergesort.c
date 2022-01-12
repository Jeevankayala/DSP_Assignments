#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500

int *swapFun(int *randArray, int n, int swapCount)
{
    for(int i=0;i<swapCount && i < n-1 ;i++)
    {
        int temp = randArray[i];
        randArray[i] = randArray[i+1];
        randArray[i+1] = temp;
    }
    return randArray;
}

int *bubble_sort(int *Arr, int n)
{
    int i,j,temp;
    for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (Arr[i] > Arr[j])
                    {
                        temp =  Arr[i];
                        Arr[i] = Arr[j];
                        Arr[j] = temp;

                    }
                }
            }
    return Arr;
}


int *Rarray(int n, int *randArray)
{
    int j;
    for(j=0;j<n;j++)
       randArray[j]=rand()%1000000;

    printf("\n Elements of the array::");
    for(int i=0;i<n;i++)
    {
     printf("\n Random number %d : %d",i+1,randArray[i]);
    }

    return randArray;
}


int *medianFun(int arr[], int left, int right, int *medianArray)
{
  int mid = (left+right-1)/2;
  int a = arr[left];
  int b = arr[mid];
  int c = arr[right];
  int pos, value;
  if(a <= b && b <= c)
  {
      value = b;
      pos = mid;
  }
  else if(c <= b && b <= a)
  {
      value = b;
      pos = mid;
  }
  else if(a <= c && c <= b)
  {
      value = c;
      pos = right;
  }
  else if(b <= c && c <= a)
  {
      value = c;
      pos= right;
  }
  else
  {
      value = a;
      pos = left;
  }
  medianArray[0] = value;
  medianArray[1] = pos;
  return medianArray;
}

int *medianFun1(int arr[], int left, int right, int *medianArray)
{
  int mid = (left+right-1)/2;
  int n4 = (right-left)/4 + left;
  int n34 = (3*(right-left))/4+ left;
  int a = arr[n4];
  int b = arr[mid];
  int c = arr[n34];
  int pos, value;
  if(a <= b && b <= c)
  {
      value = b;
      pos = mid;
  }
  else if(c <= b && b <= a)
  {
      value = b;
      pos = mid;
  }
  else if(a <= c && c <= b)
  {
      value = c;
      pos = n34;
  }
  else if(b <= c && c <= a)
  {
      value = c;
      pos= n34;
  }
  else
  {
      value = a;
      pos = n4;
  }
  medianArray[0] = value;
  medianArray[1] = pos;
  return medianArray;
}


void merge( int arr[], int temp[], int left1, int right1, int left2, int right2 )
{
	int i = left1;
	int j = left2 ;
	int k = left1 ;

	while( (i <= right1) && (j <=right2))
		temp[k++] = (arr[i]<=arr[j])? arr[i++]: arr[j++];
	while( i <= right1 )
		temp[k++]=arr[i++];
	while( j <= right2 )
		temp[k++]=arr[j++];
}


void copy(int *arr, int *temp, int left, int right )
{
	for(int i=left; i<=right; i++)
		arr[i]=temp[i];
}


void merge_sort(int *arr, int left, int right)
{
	int mid;
	int temp[MAX];
	if(left<right)
	{
		mid = (left+right)/2;
		merge_sort( arr, left , mid );
		merge_sort( arr, mid+1, right );

		merge( arr, temp, left, mid, mid+1, right );

		copy(arr,temp,left, right);
	}
}



int main()
{
	int size,choice,i,inp,k;
   while(1)
   {
   printf("Enter the size of array: ");
   scanf("%d",&size);
   printf("\n1. Random number of Integers in the range of 10^k(k=4,5,6,7)\n2. Sorted array of (1)\n3. Almost sorted array of (1)\n4. Exit \n");
   printf("\n Enter your choice (between 1 to 4) : ");
   scanf("%d", &choice);
   int *ArrayPointer;
   int Array[size];

   if(choice ==1)
    ArrayPointer = Rarray(size, Array);


   else if (choice ==2)
   {
      ArrayPointer = Rarray(size, Array);

      ArrayPointer =  bubble_sort(ArrayPointer, size);
   }

   else if (choice ==3)
   {
      ArrayPointer = Rarray(size, Array);

      ArrayPointer =  bubble_sort(ArrayPointer, size);
      int pairCount = (size*(size-1))/2;
      int swapCount =(int)( 0.01 * (float)pairCount);
      ArrayPointer = swapFun(ArrayPointer, size,swapCount);
   }

   else if(choice == 4)
   {
       break;
   }

   int l=0,u=size-1;

   clock_t start,end;
   double Time;
   start = clock();

   merge_sort( ArrayPointer, l, u);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC; // in seconds

   printf("\nSorted list is :\n");

    for( i=0; i<size; i++ )
    	printf("%d ",ArrayPointer[i]);
    printf("\n");

    printf("\n merge_sort() took %f seconds to execute \n", Time);

   }
}
