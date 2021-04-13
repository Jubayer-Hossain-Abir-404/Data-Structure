#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int m=0;
struct student
{
    char stu_id[100];
    char stu_name[100];
    float quiz;
    struct student *link;
    struct student *next;
};

void insert_stu_info(student *s,char ch[],char ch1[])
{
    student *temp;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    temp=s;
    s->next=(student*)malloc(sizeof(student));
    strcpy(s->next->stu_id,ch);
    strcpy(s->next->stu_name,ch1);
    s->next->next=NULL;

}
void insert_stu_num(student *s,float quiz)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    while(s->link!=NULL)
    {
        s=s->link;
    }
    s->link=(student*)malloc(sizeof(student));
    s->link->quiz=quiz;
    s->link->link=NULL;
}
float avg_mark_per_stu(float avg[],int n)
{
    float avg1,maximum,maximum1;
    float sum=0.0;
    float temp;
    int c=0;
    if(n==1)
    {
        maximum=avg[0];
        return maximum;
    }
    else if(n==2)
    {
        maximum=avg[0]+avg[1];
        avg1=maximum/2.0;
        return avg1;
    }
    else
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(avg[i]<avg[j])
                {
                    temp=avg[i];
                    avg[i]=avg[j];
                    avg[j]=temp;
                }
            }
        }
        for(int i=0; i<2; i++)
        {
            sum+=avg[i];
        }
        avg1=sum/2.0;
        return avg1;
    }
}
float find_maximum(float avg[],int n)
{
    float maximum;
    maximum=avg[0];
    for(int i=0; i<n; i++)
    {
        if(avg[i]>maximum)
        {
            maximum=avg[i];
            m=i;
        }
    }
    return maximum;
}
void display(student *s,float avg[],float highest)
{
    student *temp,*temp1;
    int c=0;
    int d=0;
    temp1=s;
    while(s->next!=NULL)
    {
        printf("Student ID:%s\n",s->next->stu_id);
        printf("Student Name:%s\n",s->next->stu_name);
        temp=s->next;
        printf("Quiz Numbers:\n");
        while(temp->link!=NULL)
        {
            printf("%f  ",temp->link->quiz);
            temp=temp->link;
            c++;
        }
        if(c==0)
        {
            printf("0");
        }
        if(c>2)
        {
            printf("\n%s's average of best 2 quiz number:%f",s->next->stu_name,avg[d]);
        }
        else
        {
            printf("\n%s's average of %d quiz number:%f",s->next->stu_name,c,avg[d]);
        }
        s=s->next;
        printf("\n");
        c=0;
        d++;
    }
    for(int i=0; i<m; i++)
    {
        temp1=temp1->next;
    }
    printf("%s has got the highest number in the class by getting:%f",temp1->next->stu_name,highest);
}

int main()
{
    struct student *head;
    head=(student*)malloc(sizeof(student));
    head->next=NULL;
    head->link=NULL;
    int i,n,c,p,j;
    float quiz,avg[100],highest,avg1[100];
    char stu_id[100],stu_name[100],ch;
    printf("How many students do you have in the classroom:");
    scanf("%d",&n);
    scanf("%c",&ch);
    if(n>0)
    {
        for(i=0; i<n; i++)
        {
            printf("Enter student no.%d's ID:",i+1);
            gets(stu_id);
            printf("Enter student no.%d's name:",i+1);
            gets(stu_name);
            insert_stu_info(head,stu_id,stu_name);
            printf("How many quiz's %s has taken:",stu_name);
            scanf("%d",&p);
            for(j=0; j<p; j++)
            {
                printf("Enter the quiz no.%d's number of %s:",j+1,stu_name);
                scanf("%f",&quiz);
                insert_stu_num(head,quiz);
                avg[j]=quiz;
            }
            if(p==0)
            {
                avg1[i]=0;
            }
            else
            {
                avg1[i]=avg_mark_per_stu(avg,p);
            }
            scanf("%c",&ch);
        }
        highest=find_maximum(avg1,n);
        printf("\n\n");
        display(head,avg1,highest);
    }
    else
    {
        printf("\nThere is no student in the classroom\n");
    }
    return 0;
}
