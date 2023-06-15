#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int visited[MAX];

typedef struct QNode    //����
{
    char data;
    struct QNode *next;
}*QueueP;

typedef struct
{
    QueueP front,rear;
}*Queue;

typedef struct  //ͼ���ڽӾ���
{
    char arr[MAX];
    int a[MAX][MAX];
    int vn,en;
}MGrage;

void create(MGrage *G)
{
    int i,j,k;
    printf("�����붥�����ͻ���:");
    scanf("%d %d",&G->vn,&G->en);
    int v=G->vn,e=G->en;
    printf("�����붥����Ϣ:");
    for(i=0;i<v;i++)
        scanf(" %c",&G->arr[i]);
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            G->a[i][j]=0;
    printf("������ÿ������Ӧ������������:\n");
    for(k=0;k<e;k++)
    {
        scanf("%d%d",&i,&j);
        G->a[i-1][j-1]=1;
        G->a[j-1][i-1]=1;
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            printf("%3d",G->a[i][j]);
        printf("\n");
    }
}

void inQueue(Queue Q,char k)    //β�巨���
{
    QueueP q;
    q=(QueueP)malloc(sizeof(QueueP));
    q->data=k;
    q->next=NULL;
    Q->rear->next=q;
    Q->rear=q;
}

void output(Queue Q)
{
    if(Q->front->next==NULL)
        return;
    QueueP p;
    p=Q->front->next;
    printf("%3c",p->data);
    Q->front->next=p->next;
    free(p);
    output(Q);
}

int chick(int n)
{
    int i;
    for(i=0;i<n;i++)
        if(visited[i]==0)
        return 1;
    return 0;
}

void BFSA(MGrage *G) //������ȱ���
{
    int i,j;
    Queue Q;
    Q=(Queue)malloc(sizeof(Queue));
    Q->rear=Q->front=(QueueP)malloc(sizeof(QueueP));
    for(i=0;i<G->vn;i++)
        visited[i]=0;
    for(i=0;i<G->vn;i++)
    {
        if(visited[0]==0)
        {
            visited[0]=1;
            inQueue(Q,G->arr[0]);
        }
        for(j=0;j<G->vn;j++)
        {
            if(visited[j]==0&&G->a[i][j]==1)
            {
                visited[j]=1;
                inQueue(Q,G->arr[j]);
            }
        }
    }
    printf("\n�����������Ϊ:\n");
    output(Q);
}

int main()
{
    int i;
    MGrage G;
    create(&G);
    BFSA(&G);
    return 0;
}
