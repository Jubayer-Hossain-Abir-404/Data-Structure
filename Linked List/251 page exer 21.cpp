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
void appending_list_to_itself(node *s)
{
    node *temp,*temp1,*temp2;
    int i=0,c=0;
    temp=s;
    while(s->next!=NULL)
    {
        s=s->next;
        c++;
    }
    for(i=0;i<c;i++)
    {
        temp1=temp->next;
        s->next=(node*)malloc(sizeof(node));
        s->next->data=temp1->data;
        s->next->next=temp1->next;
        s=s->next;
        temp=temp->next;
    }
    s->next=NULL;
}
void count_node(node *s)
{
    int c=0;
    while(s->next!=NULL)
    {
        c++;
        s=s->next;
    }
    //printf("\nC:%d\n",c);
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
    count_node(head);
    appending_list_to_itself(head);
    //count_node(head);
    display(head);
    return 0;
}
