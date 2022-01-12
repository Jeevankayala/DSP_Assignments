#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

int Enqueue(int r1,int f1,int r2,int f2,int r3,int f3,int r4,int f4,int Q1[],int Q2[],int Q3[],int Q4[])
{
    int value,i;
    printf("enter the value to add at end: enqueue\n");
    scanf("%d",&value);

   if (r1-f1< r2-f2) {
        if (r1-f1 < r3-f3) {
            if (r1-f1 < r4-f4) {
                Q1[r1] = value;
                 r1++;

            }
            else {
                Q4[r4] = value;
                r4++;
            }
        }
    }
    else if (r2-f2< r3-f3) {
        if (r2-f2< r4-f4) {
            Q2[r2] = value;
            r2++;
        }
        else {
            Q4[r4] = value;
                r4++;
            }
        }

    else if (r3-f3 < r4-f4) {
         Q3[++r3] = value;
         return r3;
            }

    else {
        Q4[r4] = value;
                r4++;
            }
    }

  void Dequeue(int r1,int f1,int r2,int f2,int r3,int f3,int r4,int f4,int Q1[],int Q2[],int Q3[],int Q4[])
{

   if (r1-f1> r2-f2) {
        if (r1-f1 > r3-f3) {
            if (r1-f1 > r4-f4) {
                printf("Dequeued element = %d\n",Q1[f1]);
                f1++;
            }
            else {
                printf("Dequeued element = %d\n",Q4[f4]);
                f4++;
            }
        }
    }
    else if (r2-f2< r3-f3) {
        if (r2-f2< r4-f4) {
            printf("Dequeued element = %d\n",Q2[f2]);
            f2++;
        }
        else {
                printf("Dequeued element = %d\n",Q4[f4]);
                f4++;
            }
        }

    else if (r3-f3 < r4-f4) {
         printf("Dequeued element = %d\n",Q3[f3]);
                f3++;
            }

    else {
        printf("Dequeued element = %d\n",Q4[f4]);
                f4++;
            }
    }


    void print(int r1,int f1,int r2,int f2,int r3,int f3,int r4,int f4,int Q1[],int Q2[],int Q3[],int Q4[])
    {
        int i;
        printf("Printing all queues");
        for(i=f1;i<=r1;i++)
            printf("Q1[%d]= %d ",i,Q1[i]);
            printf("\n");
        for(i=f2;i<=r2;i++)
            printf("Q2[%d]= %d ",i,Q2[i]);
            printf("\n");
        for(i=f3;i<=r3;i++)
            printf("Q3[%d]= %d ",i,Q3[i]);
            printf("\n");
        for(i=f4;i<=r4;i++)
            printf("Q4[%d]= %d ",i,Q4[i]);
            printf("\n");

    }


int main()
{
    int choice,Q1[size],Q2[size],Q3[size],Q4[size],f1,r1,f2,r2,f3,r3,f4,r4,i;
    f1=f2=f3=f4=1;
    printf("Enter 5 elememts into queue Q1 ");
    for(i=1;i<=5;i++){
      scanf("%d",&Q1[i]);
    }
    printf("Enter 3 elememts into queue Q2 ");
    for(i=1;i<=3;i++)
      scanf("%d",&Q2[i]);
    printf("Enter 2 elememts into queue Q3 ");
    for(i=1;i<=2;i++)
      scanf("%d",&Q3[i]);
    printf("Enter 6 elememts into queue Q4 ");
    for(i=1;i<=6;i++)
      scanf("%d",&Q4[i]);
      r1=5;r2=3;r3=2;r4=6;
    int s1= sizeof(Q1)/sizeof(Q1[0]);
    //r1=s1-1;
    int s2= sizeof(Q2)/sizeof(Q2[0]);
    //r2=s2-1;
    int s3= sizeof(Q3)/sizeof(Q3[0]);
    //r3=s3-1;
    int s4= sizeof(Q4)/sizeof(Q4[0]);
    //r4=s4-1;

    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Print all Queues\n4. Exit\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);
    if(choice==1) r3 = Enqueue(r1,f1,r2,f2,r3,f3,r4,f4,Q1,Q2,Q3,Q4);

    else if(choice==2) Dequeue(r1,f1,r2,f2,r3,f3,r4,f4,Q1,Q2,Q3,Q4);

    else if(choice==3) print(r1,f1,r2,f2,r3,f3,r4,f4,Q1,Q2,Q3,Q4);

    else if(choice==4)  exit(0);

    else {printf("\ninvalid choice , choose between 1 to 4\n");}
    }

}
