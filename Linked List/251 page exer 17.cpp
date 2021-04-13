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
int count_node(node *s)
{
    int c=0;
    while(s->next!=NULL)
    {
        c++;
        s=s->next;
    }
    return c;
}
void delete_node(node *s)
{
    node *temp;
    while(s->next!=NULL)
    {
        temp=s->next;
        s->next=s->next->next;
        free(temp);
    }
}
void display(node *s)
{
    if(count_node(s)==0)
    {
        printf("There is nothing to display\n");
    }
    else
    {
        printf("Display Data:\n");
        while(s->next!=NULL)
        {
            printf("%d\n",s->next->data);
            s=s->next;
        }
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
    if(count_node(head)==0)
    {
        printf("There is nothing to display and delete\n");
    }
    else
    {
        display(head);
        delete_node(head);
        display(head);
    }
    return 0;
}
