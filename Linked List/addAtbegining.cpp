#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertData(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void addAtbegining(node *s,int data)
{
    node *temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void insertAtPosition(node *s,int data,int pos)
{
    for(int i=1;i<pos;i++)
    {
        s=s->next;
    }
    node *temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void display(node *s)
{
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
}
int main()
{
    node *first=(node*)malloc(sizeof(node));
    first->next=NULL;
    int num;
    for(int i=0;i<4;i++)
    {
        printf("Input data:");
        scanf("%d",&num);
        insertData(first,num);
    }
    display(first);
    addAtbegining(first,1);
    display(first);
    insertAtPosition(first,7,6);
    printf("Display again:\n");
    display(first);
    return 0;
}
