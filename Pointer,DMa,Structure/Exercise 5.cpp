#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct student
    {
        char *name;
        float cgpa;
    };
    struct student *p;
    int n;
    printf("How many students do you want take:");
    scanf("%d",&n);
    p=(student*)malloc(n*sizeof(student));
    for(int i=0;i<n;i++)
    {
        p[i].name=(char*)malloc(30*sizeof(char));
    }
    for(int i=0;i<n;i++)
    {
        printf("Input Student No.%d's Name:",i+1);
        scanf("%s",p[i].name);
        printf("Input Student No. %d's cgpa:",i+1);
        scanf("%f",&p[i].cgpa);
    }
    float maximum=0;
    int k;
    for(int i=0;i<n;i++)
    {
        if(maximum<p[i].cgpa)
        {
            k=i;
        }
    }
    free(p->name);
    free(p);
    printf("The student who got highest cgpa:%s",p[k].name);
    return 0;
}
