#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*List;

void create(List L)
{
    int i,n;
    List p,rear;
    rear=L;
    printf("input the puality:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&rear->data);
        p=(List)malloc(sizeof(LNode));
        rear->next=p;
        rear=rear->next;
    }
    rear->next=L;
    display(L,n);
}

void display(LNode *L,int x)
{
    int i;
    List p;
    p=L;
    for(i=0;i<x;i++)
    {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}


int main()
{
    List L;
    L=(List)malloc(sizeof(LNode));
    L->next=L;
    create(L);
    return 0;
}
