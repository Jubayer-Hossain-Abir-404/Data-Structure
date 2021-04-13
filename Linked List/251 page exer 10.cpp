#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void create_a_list(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void print_result(node *s)
{
    printf("The result:\n");
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
}
int main()
{
    node *head;
    int data;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    for(int i=0;i<5;i++)
    {
        printf("Enter Data:");
        scanf("%d",&data);
        create_a_list(head,data);
    }
    print_result(head);
    return 0;
}
