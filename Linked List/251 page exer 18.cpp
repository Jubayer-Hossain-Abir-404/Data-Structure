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
void searchList(node *s,int data)
{
    int c=0,d=0;
    while(s->next!=NULL)
    {
        c++;
        if(s->next->data==data)
        {
            printf("%d has been found in %d No. position\n",data,c);
            d=1;
            break;
        }
        s=s->next;
    }
    if(d==0)
    {
        printf("%d does not exist in the list\n",data);
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
    printf("\nInput the data you want to search:");
    scanf("%d",&data);
    searchList(head,data);
    return 0;
}

