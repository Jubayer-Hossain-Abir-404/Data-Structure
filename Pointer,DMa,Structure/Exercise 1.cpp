#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    int n,i;
    printf("Input size of array:");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    printf("Array element: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    int maximum;
    maximum=p[0];
    for(i=0;i<n;i++)
    {
        if(p[i]>maximum)
        {
            maximum=p[i];
        }
    }
    printf("Expected Output:%d",maximum);
    free(p);
    return 0;
}
