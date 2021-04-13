#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node *next;
    node *prev;
};
void insert_node_at_last(node *s,int data)
{
    node *temp;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    temp=s;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
    s->next->prev=temp;
}
void insert_node_at_beginning(node *s,int data)
{
    node *temp,*temp1;
    temp1=s;
    temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
    temp->prev=s->next;
    s->next->prev=temp1;
}
void insert_node_at_any_position(node *s,int data,int pos)
{
    node *temp,*temp1;
    for(int i=1;i<pos;i++)
    {
        s=s->next;
    }
    temp=s;
    temp1=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp1;
    s->next->prev=temp;
    temp1->prev=s->next;
    temp->next=s->next;
}
void delete_node_from_last_position(node *s)
{
    node *temp,*temp1,*temp2;
    while(s->next!=NULL)
    {
        temp2=s;
        temp1=s->next;
        temp=s->next->next;
        if(temp==NULL)
        {
            break;
        }
        s=s->next;
    }
    s->next=NULL;
    free(temp1);
}
void delete_node_from_beginning(node *s)
{
    node *temp;
    temp=s->next;
    s->next=s->next->next;
    s->next->prev=s;
    free(temp);
}
void delete_node_from_any_position(node *s,int pos)
{
    node *temp;
    for(int i=1;i<pos;i++)
    {
        s=s->next;
    }
    temp=s->next;
    s->next=s->next->next;
    s->next->prev=s;
    free(temp);
}
void remove_duplicate_data(node *s)
{
    node *temp,*temp2;
    int data;
    while(s->next!=NULL)
    {
        data=s->next->data;
        temp=s->next;
        while(temp->next!=NULL)
        {
            if(temp->next->data==data)
            {
                temp2=temp->next;
                temp->next=temp->next->next;
                free(temp2);
            }
            else
            {
                temp=temp->next;
            }
        }
        s=s->next;
    }
}
void display(node *s)
{
    printf("\nDisplay Data:\n");
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
    printf("\nDisplay in Reverse:\n");
    while(s->prev!=NULL)
    {
        printf("%d\n",s->data);
        s=s->prev;
    }
}


int main()
{
    struct node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head->prev=NULL;
    int data,pos;
    for(int i=0;i<5;i++)
    {
        printf("Enter Data:");
        scanf("%d",&data);
        insert_node_at_last(head,data);
    }
    display(head);
    printf("Insert New Data:");
    scanf("%d",&data);
    insert_node_at_beginning(head,data);
    display(head);
    printf("Insert New Data:");
    scanf("%d",&data);
    printf("Insert Position:");
    scanf("%d",&pos);
    insert_node_at_any_position(head,data,pos);
    display(head);
    printf("\nFrom Last:\n");
    delete_node_from_last_position(head);
    display(head);
    printf("\nFrom First:\n");
    delete_node_from_beginning(head);
    display(head);
    printf("Enter Position:");
    scanf("%d",&pos);
    delete_node_from_any_position(head,pos);
    display(head);
    remove_duplicate_data(head);
    display(head);
}
