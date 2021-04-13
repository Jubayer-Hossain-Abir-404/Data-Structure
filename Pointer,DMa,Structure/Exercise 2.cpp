#include<stdio.h>
void sortarray(int,int*);
int main()
{
    int x[5];
    printf("Input 5 number of elements in the array:");
    for(int i=0; i<5; i++)
    {
        scanf("%d",&x[i]);
    }
    sortarray(5,x);
}
void sortarray(int n,int *p)
{
    int swaped;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(*(p+i)>*(p+j))
            {
                swaped=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=swaped;
            }
        }
    }
    printf("Expected Output: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",*p);
        p++;
    }
}

