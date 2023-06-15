#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct ArcNode
{
    int aj;
    struct ArcNode *next;
    int info;
}ArcNode;

typedef struct
{
    char data;
    ArcNode *first;
}VNode,Adj[MAX];

typedef struct
{
    Adj verlist;
    int vex,arc;
}ALGraph;

void create(ALGraph *G)
{
    int i,j,k;
    ArcNode *s;
    printf("�����붥�����ͻ���:");
    scanf("%d%d",&G->vex,&G->arc);
    int v=G->vex,a=G->arc;
    printf("�����붥����Ϣ:");
    for(i=0;i<v;i++)
    {
        scanf(" %c",&G->verlist[i].data);
        G->verlist[i].first=NULL;
    }
    printf("������ÿ������Ӧ��������������:\n");
    for(k=0;k<a;k++)
    {
        scanf("%d%d",&i,&j);
        s=(ArcNode *)malloc(sizeof(ArcNode *));
        s->aj=j-1;
        s->next=G->verlist[i-1].first;
        G->verlist[i-1].first=s;
    }
}

void DFS(ALGraph *G)
{
    int i;
    int visited[MAX];
    for(i=0;i<G->vex;i++)
        visited[i]=0;
    for(i=0;i<G->vex;i++)
        if(!visited[i])
            DFSAL(G,i,visited);
}

void DFSAL(ALGraph *G,int i,int visited[])
{
    ArcNode *p;
    printf("visit vertex:%c\n",G->verlist[i].data);
    visited[i]=1;
    p=G->verlist[i].first;
    while(p)
    {
        if(!visited[p->aj])
            DFSAL(G,p->aj,visited);
        p=p->next;
    }
}

int main()
{
    ALGraph G;
    create(&G);
    DFS(&G);
    return 0;
}
