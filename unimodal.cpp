#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int *array,n,i,midterm,max,left,right;
    cin >> n;
    array=(int *)malloc(n*sizeof(int)) ;
    for(i=0;i<n;i++)
    {
        cin >> array[i];
    }
 //  midterm=n/2;
    left=0;
    right=n-1;
    while(left<=right)
    {
        midterm=(left+right)/2;
        if((array[midterm]>array[midterm+1])&&(array[midterm-1]<array[midterm]))
        {
            max=array[midterm];
            break;
        }
        else if( array[midterm]<array[midterm+1])
        {
            left=midterm;
        }
        else 
        {
            right=midterm;
        }
    }
    cout << max;
    return 0;
}
