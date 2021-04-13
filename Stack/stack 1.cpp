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
void push1(node *s,char data)
{
    node *temp;
    temp=s->link;
    s->link=(node*)malloc(sizeof(node));
    s->link->data=data;
    s->link->link=temp;
}
void pop(node *s)
{
    node *temp;
    temp=s->link;
    s->link=s->link->link;
    free(temp);
}
void destroy_stack(node *s)
{
    node *temp;
    while(s->link!=NULL)
    {
        temp=s->link;
        s->link=s->link->link;
        free(temp);
    }
}
void convert_decimal_to_binary(node *s,int data)
{
    int digit;
    while(data>0)
    {
        digit=data%2;
        push(s,digit);
        data=data/2;
    }
}
int count_stack(node *s)
{
    int c=0;
    while(s->link!=NULL)
    {
        c++;
        s=s->link;
    }
    return c;
}
void check_parsing(node *s)
{
    char ch;
    int check;
    scanf("%c",&ch);
    while(1)
    {
        printf("Input Character:");
        scanf("%c",&ch);
        if(ch=='('||ch=='{'||ch=='[')
        {
              push1(s,ch);
        }
        else if(ch=='0')
        {
            break;
        }
        else
        {
            if(ch==')'||ch=='}'||ch==']')
            {
                check=count_stack(s);
                if(check==0)
                {
                    printf("\nOpen Parenthesis missing\n");
                }
                else
                {
                    pop(s);
                }
            }
        }
        scanf("%c",&ch);
    }
}
void display(node *s)
{
    printf("Display Data:\n");
    while(s->link!=NULL)
    {
        printf("%d\n",s->link->data);
        s=s->link;
    }
}
int main()
{
    struct node *top;
    top=(node*)malloc(sizeof(node));
    top->link=NULL;
    int data,choose;
    while(choose!=0)
    {
        printf("\nStack ADT:\n");
        printf("Press 1 for push\n");
        printf("Press 2 for pop\n");
        printf("Press 3 for display\n");
        printf("Press 4 for converting decimal to binary\n");
        printf("Press 5 for check parsing\n");
        printf("Press 6 for counting stack\n");
        printf("Press 7 for destroying stack\n");
        printf("Press 0 for EXIT\n");
        printf("\nChoose your option:");
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("Input Data:");
            scanf("%d",&data);
            push(top,data);
        }
        else if(choose==3)
        {
            display(top);
        }
        else if(choose==2)
        {
            pop(top);
        }
        else if(choose==4)
        {
            printf("Input a decimal Number:");
            scanf("%d",&data);
            convert_decimal_to_binary(top,data);
        }
        else if(choose==5)
        {
            check_parsing(top);
        }
        else if(choose==6)
        {
            count_stack(top);
            printf("\nThe number of stack right now:%d\n",count_stack(top));
        }
        else if(choose==7)
        {
            destroy_stack(top);
        }
        else if(choose==0)
        {
            printf("\nSUCCESSFULLY EXECUTED\n");
        }
    }
    return 0;
}
