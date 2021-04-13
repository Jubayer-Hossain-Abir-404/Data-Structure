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
void converting_decimal_to_hexa(node *s,int data)
{
    int digit;
    while(data>0)
    {
        digit=data%16;
        push(s,digit);
        data=data/16;
    }
}
void display(node *s)
{
    printf("\nDisplay the Hexadecimal conversion of Decimal:\n");
    while(s->link!=NULL)
    {
        if(s->link->data>=10&&s->link->data<=15)
        {
            if(s->link->data==10)
            {
                printf("A\n");
            }
            else if(s->link->data==11)
            {
                printf("B\n");
            }
            else if(s->link->data==12)
            {
                printf("C\n");
            }
            else if(s->link->data==13)
            {
                printf("D\n");
            }
            else if(s->link->data==14)
            {
                printf("E\n");
            }
            else if(s->link->data==15)
            {
                printf("F\n");
            }
        }
        else
        {
            printf("%d\n",s->link->data);
        }
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
    converting_decimal_to_hexa(top,value);
    display(top);
    return 0;
}

