#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int top;
}SeqStack;

int main()
{
    int cc;
    int num,result;
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    if(!s)
        printf("Error!");
    s->top=-1;
    qqq: printf("input:");
    scanf("%d",&num);
    int mod;
    int i=0,j=0;
    while(num>0)
    {
        i++;
        mod=num%2;
        num/=2;
        s->top++;
        s->data[s->top]=mod;
    }
    for(j;j<i;j++)
    {
        printf("%d",s->data[s->top]);
        s->top--;
    }
    printf("\n");
    printf("go on?");
    scanf("%d",&cc);
    if(cc==0)
        return 0;
    else
        goto qqq;
    getch();
}
