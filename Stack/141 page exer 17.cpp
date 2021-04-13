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
void copyStack(node *s,node *d)
{
    node *temp;
    while(s->link!=NULL)
    {
        temp=s->link;
        //d->link=(node*)malloc(sizeof(node));
        d->link=temp;
        d=d->link;
        s=s->link;
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
    for(int i=0;i<5;i++)
    {
        printf("Input Data:");
        scanf("%d",&value);
        push(top,value);
    }
    display(top);
    copyStack(top,top1);
    printf("\nAfter copying one stack from one to another\n\n");
    display(top1);
    return 0;
}
