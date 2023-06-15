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
    printf("请输入顶点数和弧数:");
    scanf("%d%d",&G->vex,&G->arc);
    int v=G->vex,a=G->arc;
    printf("请输入顶点信息:");
    for(i=0;i<v;i++)
    {
        scanf(" %c",&G->verlist[i].data);
        G->verlist[i].first=NULL;
    }
    printf("请输入每条弧对应的两个顶点的序号:\n");
    for(k=0;k<a;k++)
    {
        scanf("%d%d",&i,&j);
        s=(ArcNode *)malloc(sizeof(ArcNode *));
        s->aj=j-1;
        s->next=G->verlist[i-1].first;
        G->verlist[i-1].first=s;
    }
}

int main()
{
    ALGraph G;
    create(&G);
    return 0;
}
