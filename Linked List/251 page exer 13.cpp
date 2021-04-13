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
void deleting_negative_nodes(node *s)
{
    node *temp;
    while(s->next!=NULL)
    {
        if(s->next->data<0)
        {
            temp=s->next;
            s->next=s->next->next;
            free(temp);
        }
        else
        {
            s=s->next;
        }
    }
}
void display(node *s)
{
    printf("Display Data:\n");
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
}
int main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    int data;
    for(int i=0; i<5; i++)
    {
        printf("Input Data:");
        scanf("%d",&data);
        insertion_at_last(head,data);
    }
    display(head);
    deleting_negative_nodes(head);
    display(head);
    return 0;
}

