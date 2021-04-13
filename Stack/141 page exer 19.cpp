#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node *link;
};


void push(node *s,char x)
{
    node *temp;
    temp=s->link;
    s->link=(node*)malloc(sizeof(node));
    s->link->data=x;
    s->link->link=temp;
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
void pop(node *s,char ch)
{
    while(s->link!=NULL)
    {
        s=s->link;
    }
    s->link=(node*)malloc(sizeof(node));
    s->link->data=ch;
    s->link->link=NULL;
}
void checking_palindrome(node *s,node *s1)
{
    int d=0;
    int c=count_stack(s);
    for(int i=0; i<c; i++)
    {
        if(s->link->data==s1->link->data||s->link->data==s1->link->data+32||s->link->data==s1->link->data-32)
        {
            d++;
        }
        s=s->link;
        s1=s1->link;
    }
    //printf("\nD:%d\n",d);
    //printf("C:%d\n",c);
    if(d==c)
    {
        printf("The string is palindrome\n");
    }
    else
    {
        printf("The string is not palindrome\n");
    }
}
void display(node *s)
{
    printf("Display:\n");
    while(s->link!=NULL)
    {
        printf("%c\n",s->link->data);
        s=s->link;
    }
}
int main()
{
    node *top,*top1;
    top=(node*)malloc(sizeof(node));
    top->link=NULL;
    top1=(node*)malloc(sizeof(node));
    top1->link=NULL;
    char *ch;
    ch=(char*)malloc(50*sizeof(char));
    printf("Enter the string:");
    gets(ch);
    int c=strlen(ch);
    for(int i=0; i<c; i++)
    {
        if((ch[i]>='A'&&ch[i]<='Z')||(ch[i]>='a'&&ch[i]<='z'))
        {
            push(top,ch[i]);
        }
    }
    //display(top);
    for(int i=0; i<c; i++)
    {
        if((ch[i]>='A'&&ch[i]<='Z')||(ch[i]>='a'&&ch[i]<='z'))
        {
            pop(top1,ch[i]);
        }
    }
    //display(top1);
    checking_palindrome(top,top1);
    free(ch);
    return 0;
}
