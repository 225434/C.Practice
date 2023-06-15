#include <stdio.h>
#include <stdlib.h>

typedef struct QNode    //队列
{
    int data;
    struct QNode *next;
}*QueueP;

typedef struct
{
    QueueP front,rear;
}*Queue;

void inQueue(Queue Q)    //尾插法入队
{
  QueueP q;
  int i;
  for(i=0;i<4;i++)
  {
    q=(QueueP)malloc(sizeof(QueueP));
    scanf("%d",&q->data);
    q->next=NULL;
    Q->rear->next=q;
    Q->rear=q;
  }
}

void output(Queue Q)
{
    QueueP p;
    int i;
    
    for(i=0;i<4;i++)
    {
      p=Q->front->next;
      printf("%d",p->data);
      Q->front->next=Q->front->next->next;
    }
    
    if(Q->front->next==NULL)
        Q->rear=Q->front;
}

int main()
{
  int i,x;
  Queue Q;
  Q=(Queue)malloc(sizeof(Queue));
  Q->rear=Q->front=(QueueP)malloc(sizeof(QueueP));
  inQueue(Q);
  output(Q);
  return 0;
}
