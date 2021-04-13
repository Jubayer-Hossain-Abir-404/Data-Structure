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
bool swaped(int x,int y,node *s)
{
    if(x<=count_node(s)&&y<=count_node(s))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void swap_node(int x,int y,node *s)
{
    node *temp,*temp1,*temp2,*temp3,*temp4;
    temp=s;
    temp1=s;
    for(int i=1;i<x;i++)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp4=temp->next->next;
    for(int i=1;i<y;i++)
    {
        temp2=temp->next;
    }
    temp3=temp->next;
    temp->next=temp3;
    //temp3-next=temp4;
    temp2->next=temp;
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
    int data,x,y;
    for(int i=0; i<5; i++)
    {
        printf("Input Data:");
        scanf("%d",&data);
        insertion_at_last(head,data);
    }
    display(head);
    printf("Enter two position to swap:");
    scanf("%d%d",&x,&y);
    if(swaped(x,y,head)==true)
    {
        printf("Swaping can be done\n");
        swap_node(x,y,head);
        display(head);
    }
    else
    {
        printf("Such position does not exist\n");
    }
    return 0;
}
