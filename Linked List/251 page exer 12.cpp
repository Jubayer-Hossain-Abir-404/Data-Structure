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
int count_negative_node(node *s)
{
    int c=0;
    while(s->next->data<0)
    {
        c++;
        s=s->next;
    }
    return c;
}
void deleting_negative_nodes(node *s)
{
    node *temp,*temp1;
    int c=count_node(s);
    int d=count_negative_node(s);
    if(c==d)
    {
        while(s->next!=NULL)
        {
            temp=s->next;
            s->next=s->next->next;
            free(temp);
        }
    }
    else
    {
        while(s->next!=NULL)
        {
            temp=s;
            while(temp->next!=NULL)
            {
                if(temp->next->data<0)
                {
                    temp1=temp->next;
                    temp->next=temp->next->next;
                    free(temp1);
                }
                else
                {
                    temp=temp->next;
                }
            }
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
void display1(node *s)
{
    if(count_node(s)==count_negative_node(s))
    {
        printf("There is nothing to display because all the nodes are negative\n");
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
    display(head);
    deleting_negative_nodes(head);
    display1(head);
    return 0;
}
