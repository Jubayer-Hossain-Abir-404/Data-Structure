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
void insertion_at_begining(node *s,int data)
{
    node *temp;
    temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void insertion_at_any_point(node*s,int data,int pos)
{
    node *temp;
    for(int i=1;i<pos;i++)
    {
        s=s->next;
    }
    temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void delete_at_begining(node*s)
{
    node *temp;
    temp=s->next;
    s->next=s->next->next;
    free(temp);
}
void delete_at_last(node*s)
{
    node *temp,*temp1;
    while(s->next!=NULL)
    {
        temp1=s->next;
        temp=s->next->next;
        if(temp==NULL)
        {
            break;
        }
        s=s->next;
    }
    free(temp1);
    s->next=NULL;
}
void delete_at_any_point(node *s,int pos)
{
    node *temp,*temp1;
    for(int i=1;i<pos;i++)
    {
        s=s->next;
        temp=s->next;
    }
    s->next=s->next->next;
    free(temp);
}
void display(node *s)
{
    printf("Display:\n");
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
}
int main()
{
    struct node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    int n,num,pos;
    printf("      Linked Menu List  \n");
    printf("press 1 for Insertion at Last\n");
    printf("press 2 for Insertion at Beginning\n");
    printf("press 3 for Insertion at any point\n");
    printf("Press 4 for Delete at Beginning\n");
    printf("press 5 for Delete last\n");
    printf("Press 6 for Delete at any point\n");
    printf("Press 7 for display\n\n");
    printf("Press 0 for exit\n\n");
    while(n!=0)
    {
        printf("Choose your Option:");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Input Data:");
            scanf("%d",&num);
            insertion_at_last(head,num);
        }
        else if(n==2)
        {
            printf("Input Data:");
            scanf("%d",&num);
            insertion_at_begining(head,num);
        }
        else if(n==3)
        {
            printf("Input Data:");
            scanf("%d",&num);
            printf("Enter the position:");
            scanf("%d",&pos);
            insertion_at_any_point(head,num,pos);
        }
        else if(n==4)
        {
            delete_at_begining(head);
        }
        else if(n==5)
        {
            delete_at_last(head);
        }
        else if(n==6)
        {
            printf("Enter the position:");
            scanf("%d",&num);
            delete_at_any_point(head,num);
        }
        else if(n==7)
        {
            display(head);
        }
    }
    printf("\n\n\n         SUCCESFULLY EXECUTED");
    return 0;
}
