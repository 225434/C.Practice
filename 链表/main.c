#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *next;
}StackNode,*LinkStack;

void inits(StackNode *s,int mod)
{
    LinkStack p;
    p=(LinkStack)malloc(sizeof(LinkStack));
    p->data=mod;
    p->next=s->next;
    s->next=p;
}

void out(StackNode *s)
{
    LinkStack q;
    q=s->next;
    printf("%d",q->data);
    s->next=q->next;
    free(q);
}


int main()
{
    int num;
    int i=0,j=0,mod;
    StackNode *s,*p;
    s=(LinkStack)malloc(sizeof(LinkStack));
    s->next=NULL;
    printf("input:");
    scanf("%d",&num);
    while(num>0)
    {
        i++;
        mod=num%2;
        num/=2;
        inits(s,mod);
    }
     for(j;j<i;j++)
    {
        out(s);
    }
    printf("\n");
    return 0;
    getch();
}
