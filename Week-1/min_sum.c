// minimum sum from array
#include<stdio.h>
#include<stdlib.h>
void min_sum();

void main(){
int arr[]={1, 4, 45, 6, 0, 19 };
//int arr2[6]={0};
int min_len,x=51,curr_sum=0,start=0,end=0,len,i,n,j;
len=sizeof(arr)/sizeof(arr[0]);
int arr2[6]={0};
n=len;
curr_sum=0;
min_len=len+1;
i=0;
    for(start=0,end=0;end<n;){
        for(;curr_sum <= x && end < n;){
            curr_sum=curr_sum+arr[end];
            arr2[i++]=arr[end];
            end++;
        }

        for(j=0;j<n;j++){
            printf("\t %d",arr2[j]);
        }
        printf("\t before\n");

        for(;curr_sum>x && start<len;){
        if(end-start < min_len){
            min_len=end-start;
        }
        curr_sum=curr_sum-arr[start];
        for(j=0;j<n;j++){if(arr2[j]==arr[start]){ arr2[j]= 0; }}
        start++;
    }
    }
printf("\n min len is %d\n",min_len);
printf("\n\nArray");
for(int k=start;k<=end;k++){
    printf("\t%d",arr[k]);
}
printf("\n\n");
for(j=0;j<n;j++){
    printf("\t %d",arr2[j]);
}


}
