#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void push(node *s,int data)
{
    node *temp;
    temp=s->link;
    s->link=(node*)malloc(sizeof(node));
    s->link->data=data;
    s->link->link=temp;
}

void catStack(node *s,node *s1)
{
    node *temp;
    int i=0;
    while(s->link!=NULL)
    {
        s=s->link;
    }
    while(s1->link!=NULL)
    {
        temp=s1->link;
        s->link=temp;
        s=s->link;
        s1=s1->link;
    }
}

void display(node *s)
{
    printf("Display Data:\n");
    while(s->link!=NULL)
    {
        printf("%d\n",s->link->data);
        s=s->link;
    }
}

int main()
{
    node *top,*top1;
    top=(node*)malloc(sizeof(node));
    top->link=NULL;
    top1=(node*)malloc(sizeof(node));
    top1->link=NULL;
    int value;
    for(int i=0; i<5; i++)
    {
        printf("Enter Data:");
        scanf("%d",&value);
        push(top,value);
    }
    display(top);
    for(int i=0; i<5; i++)
    {
        printf("Enter Data:");
        scanf("%d",&value);
        push(top1,value);
    }
    display(top1);
    catStack(top,top1);
    printf("\nAfter Concatenating:\n\n");
    display(top);
    return 0;

}
