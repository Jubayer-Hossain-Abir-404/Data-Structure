#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    char data;
    struct node *next;
};

void insert_at_last(node *s,char data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void check_character(node *s)
{
    char ch='!';
    int a[1000]= {0},i,j=0,m[100];
    while(s->next!=NULL)
    {
        i=33;
        while(ch<='z')
        {
            if(s->next->data==ch)
            {
                a[i]++;
                if(a[i]==1)
                {
                    m[j]=i;
                    j++;
                }
                break;
            }
            ch++;
            i++;
        }
        ch='!';
        s=s->next;
    }
    for(int n=0; n<j; n++)
    {
        printf("%d:%d\n",m[n],a[m[n]]);
    }
    int temp;
    for(int n=0;n<j-1;n++)
    {
        for(int ac=n+1;ac<j;ac++)
        {
            if(m[n]>m[ac])
            {
                temp=m[n];
                m[n]=m[ac];
                m[ac]=temp;
            }
        }
    }
    printf("\nAfter sorting in ascending order:\n");
    for(int n=0; n<j; n++)
    {
        printf("%d:%d\n",m[n],a[m[n]]);
    }
}
int main()
{
    struct node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    char ch[100],mh;
    int n,i;
    printf("How many characters do you want to take:");
    scanf("%d",&n);
    scanf("%c",&mh);
    for(i=0; i<n; i++)
    {
        printf("Enter character:");
        scanf("%c",&mh);
        ch[i]=mh;
        insert_at_last(head,mh);
        scanf("%c",&mh);
    }
    ch[i]='\0';
    printf("\nThe string is:%s\n\n",ch);
    check_character(head);
    return 0;
}
