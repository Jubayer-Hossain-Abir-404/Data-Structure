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
void appending_two_list(node *s,node *s1)
{
    node *temp;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    while(s1->next!=NULL)
    {
        s->next=(node*)malloc(sizeof(node));
        temp=s1->next;
        s->next->data=temp->data;
        s->next->next=temp->next;
        s=s->next;
        s1=s1->next;
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
void display1(node *s1)
{
    printf("Display Data:\n");
    while(s1->next!=NULL)
    {
        printf("%d\n",s1->next->data);
        s1=s1->next;
    }
}
int main()
{
    node *head,*head1;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head1=(node*)malloc(sizeof(node));
    head1->next=NULL;
    int data;
    printf("Input the 1st list:\n");
    for(int i=0; i<5; i++)
    {
        printf("Input Data:");
        scanf("%d",&data);
        insertion_at_last(head,data);
    }
    printf("Input the 2nd list:\n");
    for(int i=0;i<5;i++)
    {
        printf("Input Data:");
        scanf("%d",&data);
        insertion_at_last(head1,data);
    }
    display(head);
    display(head1);
    appending_two_list(head,head1);
    display(head);
    return 0;
}

