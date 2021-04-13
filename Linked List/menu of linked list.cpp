#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert_node_at_last(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void insert_node_at_beginning(node *s,int data)
{
    node *temp;
    temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void insert_node_at_any_position(node *s,int data,int pos)
{
    node *temp;
    for(int i=1; i<pos; i++)
    {
        s=s->next;
    }
    temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void delete_node_from_last_position(node *s)
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
    s->next=NULL;
    free(temp1);
}
void delete_node_from_beginning(node *s)
{
    node *temp;
    temp=s->next;
    s->next=s->next->next;
    free(temp);
}
void delete_node_from_any_position(node *s,int pos)
{
    node *temp;
    for(int i=1; i<pos; i++)
    {
        s=s->next;
    }
    temp=s->next;
    s->next=s->next->next;
    free(temp);
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
void reverse_node(node*s)
{
    node *curr,*prev,*after;
    prev=NULL;
    curr=s->next;
    while(curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    s->next=prev;
}
void remove_duplicate_data(node *s)
{
    node *temp;
    int data;
    while(s->next!=NULL)
    {
        data=s->next->data;
        temp=s->next;
        while(temp->next!=NULL)
        {
            if(temp->next->data==data)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        s=s->next;
    }
}

int main()
{
    struct node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    int choose,value,pos;
    while(choose!=0)
    {
        printf("       Create A MENU\n\n");
        printf("   1.Press 1 to Insert new node\n");
        printf("   2.Press 2 to Insert node at beginning\n");
        printf("   3.Press 3 to Insert new node at any position\n");
        printf("   4.Press 4 to Delete node from last position\n");
        printf("   5.Press 5 to Delete node from beginning\n");
        printf("   6.Press 6 to Delete node from any position\n");
        printf("   7.Press 7 to Display\n\n");
        printf("   8.Press 8 to reverse node\n");
        printf("   9.Press 9 to remove duplicate data from list\n");
        printf("     Press 0 to END\n\n");
        printf("Choose your option:");
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("Input Data:");
            scanf("%d",&value);
            insert_node_at_last(head,value);
        }
        else if(choose==2)
        {
            printf("Input Data:");
            scanf("%d",&value);
            insert_node_at_beginning(head,value);
        }
        else if(choose==3)
        {
            printf("Input Data:");
            scanf("%d",&value);
            printf("Enter position:");
            scanf("%d",&pos);
            insert_node_at_any_position(head,value,pos);
        }
        else if(choose==4)
        {
            delete_node_from_last_position(head);
        }
        else if(choose==5)
        {
            delete_node_from_beginning(head);
        }
        else if(choose==6)
        {
            printf("Enter Position:");
            scanf("%d",&pos);
            delete_node_from_any_position(head,pos);
        }
        else if(choose==7)
        {
            display(head);
        }
        else if(choose==0)
        {
            printf("    SUCCESFULLY EXECUTED");
        }
        else if(choose==8)
        {
            reverse_node(head);
        }
        else if(choose==9)
        {
            remove_duplicate_data(head);
        }
    }
    return 0;
}
