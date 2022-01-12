#include <stdio.h>
int main()
{
    char str[50];
    printf("Enter the String : ");
    scanf("%[^\n]",str);
    int n=strlen(str);
    int LP[n][n];
    memset(LP,0,sizeof(LP));

    for(int i=0;i<n;i++)
    {
        LP[i][i]=1;
    }
    int len=1,x=0;
    for(int i=0;i<n-1;i++)
    {
      if(str[i]==str[i+1])
      {
        LP[i][i+1]=1;
        if(len<2)
        {
          len=2;
          x=i;
        }
      }
    }
    for(int i=3;i<=n;i++)
    {
      for(int j=0;j<n-i+1;j++)
      {
        int k=j+i-1;
        if(str[j]==str[k])
        {
          if(LP[j+1][k-1]==1)
          {LP[j][k]=1;
          if(len<i)
          len=i;
            x=j;
          }
        }
      }
    }
    printf("Longest palindrome Found in the String is : ");
    for(int i=x;i<x+len;i++)
    printf("%c",str[i]);
    printf("\n");
    printf("The length of Longest Palindrome is : %d",len);
    printf("\n");
    return 0;
}
