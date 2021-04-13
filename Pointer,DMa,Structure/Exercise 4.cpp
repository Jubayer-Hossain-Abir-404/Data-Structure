#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    struct the_string
    {
        char *name;
    };
    struct the_string *p;
    int c=0;
    p=(the_string*)malloc(sizeof(the_string));
    p->name=(char*)malloc(30*sizeof(char));
    printf("Please Enter the string:");
    gets(p->name);
    c=strlen(p->name);
    for(int i=c-1;i>=0;i--)
    {
        printf("%c",p->name[i]);
    }
    free(p->name);
    free(p);
    return 0;
}
