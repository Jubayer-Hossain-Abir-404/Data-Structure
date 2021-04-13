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
void reverse_stack(node *s)
{
    node *curr,*prev,*after;
    prev=NULL;
    curr=s->link;
    while(curr!=NULL)
    {
        after=curr->link;
        curr->link=prev;
        prev=curr;
        curr=after;
    }
    s->link=prev;
}
int count_stack(node *s)
{
    int c=0;
    while(s->link!=NULL)
    {
        c++;
        s=s->link;
    }
    return c;
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
    node *top;
    top=(node*)malloc(sizeof(node));
    top->link=NULL;
    int value;
    for(int i=0;i<5;i++)
    {
        printf("Input Data:");
        scanf("%d",&value);
        push(top,value);
    }
    display(top);
    int c=count_stack(top);
    reverse_stack(top);
    display(top);
}
