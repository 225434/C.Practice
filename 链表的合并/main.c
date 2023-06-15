#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Insert(LNode *L,int x)
{
    int i;
    int n;
    LinkList p,rear;
    rear=L;
    printf("input A's data:");
    for(i=0;i<x;i++)
    {
        scanf("%d",&n);
        p=(LNode *)malloc(sizeof(LNode));
        p->data=n;
        rear->next=p;
        rear=p;
    }
    rear->next=NULL;
    display(L,x);
}

void display(LNode *L,int x)
{
    int i;
    LinkList p;
    p=L->next;
    while(p)
    {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}

void mix(LNode *La,LNode *Lb,int a,int b)
{
    LinkList Lc;
    Lc=(LNode *)malloc(sizeof(LNode));
    Lc->next=NULL;
    LinkList ma,mb,mc;
    ma=La->next;
    mb=Lb->next;
    mc=Lc=La;
    while(ma&&mb)
    {
        if(ma->data<=mb->data)
        {
            mc->next=ma;
            mc=ma;
            ma=ma->next;
        }
        else
        {
            mc->next=mb;
            mc=mb;
            mb=mb->next;
        }
    }
    mc->next=ma?ma:mb;
    free(Lb);
    display(Lc,a+b);
}

int main()
{
    LinkList La,Lb;
    int a,b;
    La=(LNode *)malloc(sizeof(LNode));
    Lb=(LNode *)malloc(sizeof(LNode));
    La->next=NULL;
    Lb->next=NULL;
    printf("input A's digit:");
    scanf("%d",&a);
    Insert(La,a);
    printf("input B's digit:");
    scanf("%d",&b);
    Insert(Lb,b);
    mix(La,Lb,a,b);
    cin.get();
    getch();
    return 0;
}
