#include <stdio.h>
#include <stdlib.h>

typedef struct QNode    //队列
{
    int data;
    struct QNode *next;
}QNode,*Queue;

void inQueue(Queue Q)
{
    Queue q,rear;
    rear=Q;
    int n;
    int i;
    printf("输入个数:");
    scanf("%d",&n);
    printf("input data:");
    for(i=0;i<n;i++)
    {
        q=(Queue)malloc(sizeof(Queue));
        scanf("%d",&q->data);
        rear->next=q;
        rear=rear->next;
    }
    rear->next=NULL;
    display(Q);
}

void display(Queue Q)
{
    Queue p;
    p=Q;
    if(p->next==NULL)
        return;
    printf("%3d",p->next->data);
    p=p->next;
    display(p);
}

int main()
{
    Queue Q;
    Q=(Queue)malloc(sizeof(Queue));
    Q->next=NULL;
    inQueue(Q);

    return 0;
}
