#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void Radix_sort(int array[], int n) {  // Radix sort Function
  int max = Max(array, n);

  for (int place = 1; max / place > 0; place *= 10)  // counting sort
    Counting_Sort(array, n, place);
}


void Counting_Sort(int array[], int n, int place) {  // counting sort function
  int output[n + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < n; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < n; i++)    // Loop to Calculate the count of elements
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < 10; i++)  // cumulative count
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++)
    array[i] = output[i];
}



int Max(int arr[], int n) {
  int max = arr[0];

  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}


int main()
{
    int arr[50],n;

    printf("Enter No. of Elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Element No. %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n Elements before sorting : \n");
    for(int i = 0; i<n; i++)
    {
        printf("%d  ", arr[i] );
    }
    Radix_sort(arr, n);

    printf("\n\nElements After Radix sort: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}
