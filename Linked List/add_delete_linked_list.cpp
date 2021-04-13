#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertData(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void insertFirst(node *s,int data)
{
    node *temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}
void deleteFirst(node *s)
{
    s->next=s->next->next;
}
void deleteLast(node *s)
{
    node *temp;
    while(s->next!=NULL)
    {
        temp=s->next->next;
        if(temp==NULL)
        {
            break;
        }
        s=s->next;
    }
    s->next=NULL;
}
void deleteAtAnypoint(node *s,int data)
{
    node *temp;
    while(s->next!=NULL)
    {
        if(s->next->data==data)
        {
            s->next=s->next->next;

            break;
        }
        s=s->next;
    }
}
void insertafter(node *s,int searched,int data)
{
    node *temp;
    while(s->next!=NULL)
    {
        if(s->next->data==searched)
        {
            temp=s->next->next;
            s->next->next=(node*)malloc(sizeof(node));
            s->next->next->data=data;
            s->next->next->next=temp;
            break;
        }
        s=s->next;
    }
}
void insertLast(node *s,int data)
{
    node *temp;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void countnode(node *s)
{
    int c=0;
    while(s->next!=NULL)
    {
        c++;
        s=s->next;
    }
    printf("\nThe number of nodes are:%d\n",c);
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
void search_list(node *s,int data)
{
    int c=0;
    while(s->next!=NULL)
    {
        if(s->next->data==data)
        {
            printf("\n%d has been found\n",s->next->data);
            c++;
            break;
        }
        s=s->next;
    }
    if(c==0)
    {
        printf("\n%d has not been found\n",data);
    }
}
int main()
{
    node *first;
    first=(node*)malloc(sizeof(node));
    first->next=NULL;
    int i,num;
    for(i=0; i<4; i++)
    {
        printf("Input Data:");
        scanf("%d",&num);
        insertData(first,num);
    }
    display(first);
    countnode(first);
    insertFirst(first,2);
    printf("After Inserting first:\n");
    display(first);
    countnode(first);
    insertafter(first,9,10);
    printf("After inserting after:\n");
    display(first);
    countnode(first);
    deleteAtAnypoint(first,9);
    printf("After deleting at any point:\n");
    display(first);
    countnode(first);
    deleteLast(first);
    printf("After deleting last:\n");
    display(first);
    countnode(first);
    deleteFirst(first);
    printf("After Deleting first:\n");
    display(first);
    countnode(first);
    printf("After Inserting last:\n");
    insertLast(first,20);
    display(first);
    countnode(first);
    search_list(first,20);
    return 0;
}
