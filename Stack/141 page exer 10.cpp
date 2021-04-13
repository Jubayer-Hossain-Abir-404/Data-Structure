#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void push(node *s,int data)
{
    node *temp;
    temp=s->link;
    s->link=(node*)malloc(sizeof(node));
    s->link->data=data;
    s->link->link=temp;
}
void converting_decimal_to_octal(node *s,int data)
{
    int digit;
    while(data>0)
    {
        digit=data%8;
        push(s,digit);
        data=data/8;
    }
}
void display(node *s)
{
    printf("\nDisplay the Octal conversion of Decimal:\n");
    while(s->link!=NULL)
    {
        printf("%d\n",s->link->data);
        s=s->link;
    }
}
int main()
{
    node *top;
    int value;
    top=(node*)malloc(sizeof(node));
    top->link=NULL;
    printf("Enter the Decimal Number:");
    scanf("%d",&value);
    converting_decimal_to_octal(top,value);
    display(top);
    return 0;
}
