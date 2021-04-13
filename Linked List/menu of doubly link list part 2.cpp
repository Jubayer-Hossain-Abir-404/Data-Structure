#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    for(int i=1; i<pos; i++)
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
    s->next->prev=s;
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
    s->next->prev=s;
    free(temp);
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
                temp->next->prev=temp;
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

int main()
{
    struct node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head->prev=NULL;
    int choose,value,pos,c,d;
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
        printf("   8.Press 8 to remove duplicate data from list\n");
        printf("     Press 0 to END\n\n");
        printf("Choose your option:");
        scanf("%d",&choose);
        c=count_node(head);
        if(choose==1)
        {
            printf("Input Data:");
            scanf("%d",&value);
            insert_node_at_last(head,value);
        }
        else if(choose==2&&c==0)
        {
            printf("\nThere is no node at first place to insert node at beginning\n\n");
        }
        else if(choose==2&&c>0)
        {
            printf("Input Data:");
            scanf("%d",&value);
            insert_node_at_beginning(head,value);
        }
        else if(choose==3&&c==0)
        {
            printf("\nThere is no node at first place to insert node at any position\n\n");
        }
        else if(choose==3&&c>0)
        {
            printf("Input Data:");
            scanf("%d",&value);
            printf("Enter position:");
            scanf("%d",&pos);
            if(pos<=c)
            {
                insert_node_at_any_position(head,value,pos);
            }
            else
            {
                printf("\nYou cannot create node in such position because such position does not exist\n\n");
            }
        }
        else if(choose==4&&c==0)
        {
            printf("\nYou cannot delete node in last position because there is no node right now\n\n");

        }
        else if(choose==4&&c>0)
        {
            delete_node_from_last_position(head);
        }
        else if(choose==5&&(c==1||c==0))
        {
            printf("\nYou cannot delete node in such position\n\n");
        }
        else if(choose==5&&c>1)
        {
            delete_node_from_beginning(head);
        }
        else if(choose==6&&c==0)
        {
            printf("\nYou can not delete any node because right now no node exists\n\n");
        }
        else if(choose==6&&c>0)
        {
            printf("Enter Position:");
            scanf("%d",&pos);
            if(pos<c)
            {
                delete_node_from_any_position(head,pos);
            }
            else
            {
                printf("\nYou cannot delete node in such position because such position does not exist\n\n");
            }
        }
        else if(choose==7)
        {
            if(c>0)
            {
                display(head);
            }
            else
            {
                printf("\nThere is nothing to display\n\n");
            }
        }
        else if(choose==0)
        {
            printf("    SUCCESFULLY EXECUTED");
        }
        else if(choose==8&&c==0)
        {
            printf("\nThere is nothing to remove\n\n");
        }
        else if(choose==8)
        {
            remove_duplicate_data(head);
        }
        else
        {
            printf("\nYou have taken Wrong Input\n\n");
        }
    }
    return 0;
}
