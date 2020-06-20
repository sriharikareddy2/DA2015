#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void printlists(struct node *a,struct node *b,int t)
{
    int m=0,n=0,r,i;
    struct node *pa,*pb,*com;
    pa=a;
    pb=b;
    while(pa!=NULL)
    {
        pa=pa->next;
        m++;
    }
    while(pb!=NULL)
    {
        pb=pb->next;
        n++;
    }
    r=m+n-t;
    pa=a;
    pb=b;
    //com=NULL;
    printf("\n\n +++ Part(b)");
    printf("\nIntial part of A : ");
    //fflush(stdout);
    for(i=0;i<m-r;i++)
    {
        printf("%d ",pa->data);
        pa=pa->next;
    }
    com=pa;
    pb=b;
     printf("\nIntial part of B : ");
     //fflush(stdout);
    for(i=0;i<n-r;i++)
    {
        printf("%d ",pb->data);
       // fflush(stdout);
        pb=pb->next;
    }
    pa=com;
    printf("\nCommon part      : ");
    while(pa!=NULL)
    {
        printf("%d ",pa->data);
        pa=pa->next;
    }
    return ;
}
 int main()
{
    int t,i,ismerged,mer,aorb;
    struct node *A, *B,*new,*preva,*prevb,*p;
    A=NULL;
    B=NULL;
    preva=NULL;
    prevb=NULL;
    printf("t= ");
    scanf("%d",&t);
    ismerged=0;
    i=t+1;
    while(i--)
    {
     new=(struct node *)malloc(sizeof(struct node));
     new->data=rand();
     new->next=NULL;
     if(ismerged==0)
     {
         mer=(rand())%5;
         if(mer==0)
         ismerged=1;
         if(ismerged==1)
         {
             if((A==NULL)&&(B==NULL))
             {
                 A=new;
                 B=new;
                 preva=new;
                 prevb=new;
             }
             else if(A==NULL)
             {
                 A=new;
                 prevb->next=new;
                 preva=new;
                 prevb=new;


             }
              else if(B==NULL)
             {
                 B=new;
                 preva->next=new;
                 preva=new;
                 prevb=new;

             }
             else
             {
                 preva->next=new;
                 prevb->next=new;
             }
         }
         else
         {
             aorb=rand()%8;
             if((aorb==0)||(aorb==1)||(aorb==7)||(aorb==6))
             {
                 if(A==NULL)
                 {
                     A=new;
                     preva=new;
                 }

                 else{
                     preva->next=new;
                     preva=new;
                 }
             }
              else{
                      if(B==NULL)
                      {
                        B=new;
                         prevb=new;
                     }
                     else{
                         prevb->next=new;
                         prevb=new;
                     }

              }
         }

     }
     else
        {
            preva->next=new;
            prevb->next=new;
            //prevb->next=preva->next;
            preva=new;
            prevb=new;
        }



    }
    printf("\n +++ Part (a)");
    printf("\nList A           : ");
    p=A;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\nList B           : ");
    p=B;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }


    printlists(A,B,t);

    return 0;
}
