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
        p=(List)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        rear->next=p;
        rear=rear->next;
    }
    rear->next=NULL;
    display(L,n);
}

void display(List L)
{
    List p;
    p=L;
    if(p->next==NULL)
        return;
    printf("%3d",p->next->data);
    p=p->next;
    display(p);
    free(p);
}


int main()
{
    List L;
    L=(List)malloc(sizeof(LNode));
    L->next=NULL;
    create(L);
    return 0;
}
