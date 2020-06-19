#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,t,*A,i,sum=0,j,flag=0;
    printf("\nn=");
    scanf("%d",&n);
    printf("\nt=");
    scanf("%d",&t);
    A=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    i=0;
    for(j=0;j<n;j++)
    {
        
        if(sum==t)
        {
            flag=1;
            break;
        }
        else if(sum>t)
        {
            sum=sum-A[i];
            j--;
            if(sum==t)
        {
            i++;
            flag=1;
            break;
        }
        i++;
        
            
        }
        else
            sum+=A[j];
        
    }
    if(flag)
    {
        printf("\n+++ Subarray found...");
        printf("\n%d= ",t);
        for(flag=i;flag<=j;flag++)
        {
            if(flag==j)
            printf("%d ",A[flag]);
            else
            printf("%d + ",A[flag]);
        }
        printf("\n");
    }
    else
    {
        printf("\nNO subarray found\n");
    }
    return 0;
}
