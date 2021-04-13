#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    int n,c=0,d=0,k,a=0,e;
    printf("How many values do you want to take:");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    printf("Input the values:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",(p+i));
        if(*(p+i)>=0)
        {
            c++;
        }
    }
    for(int i=0; i<n; i++)
    {
        while(*(p+i)<0)
        {
            for(k=i+1; k<n; k++)
            {
                *(p+i)=*(p+k);
                //for(int j=k+1; j<n; j++)
                {
                    //*(p+k)=*(p+j);
                }
                if(*(p+i)>=0)
                {
                    break;
                }
            }
            if(k==n&&*(p+i)<0)
            {
                d=1;
                break;
            }
        }
        if(d==1)
        {
            break;
        }
    }
    printf("After deleting all the negative numbers:");
    if(c!=0)
    {
        for(int i=0; i<c; i++)
        {
            printf("%d ",*(p+i));
        }
    }
    else
    {
        printf("\nAfter deleting all the negative numbers there is nothing to display\n");
    }
    free(p);
    return 0;
}
