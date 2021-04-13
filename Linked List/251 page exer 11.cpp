#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertion_at_last(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
int traverse_to_find_the_smallest(node *s)
{
    int minimum;
    minimum=s->next->data;
    while(s->next!=NULL)
    {
        if(s->next->data<minimum)
        {
            minimum=s->next->data;
        }
        s=s->next;
    }
    return minimum;
}
int main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    int data;
    for(int i=0; i<5; i++)
    {
        printf("Enter Data:");
        scanf("%d",&data);
        insertion_at_last(head,data);
    }
    printf("The data in the node with the smallest key value is:%d",traverse_to_find_the_smallest(head));
    return 0;
}
