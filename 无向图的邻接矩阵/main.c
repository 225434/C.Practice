#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    char vexs[MAX];
    int edges[MAX][MAX];
    int vn,en;
}MGrage;

void Create(MGrage *G)
{
    int i,j,k;
    char ch;
    printf("�����붥�����ͻ���:");
    scanf("%d%d",&G->vn,&G->en);
    int v=G->vn,e=G->en;
    printf("�����붥����Ϣ:");
    for(i=0;i<v;i++)
        scanf(" %c",&G->vexs[i]);
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            G->edges[i][j]=0;
    printf("������ÿ������Ӧ��������������:\n");
    for(k=0;k<e;k++)
    {
        scanf("%d%d",&i,&j);
        G->edges[i-1][j-1]=1;
        G->edges[j-1][i-1]=1;
    }
    for(i=0;i<e;i++)
    {
        for(j=0;j<e;j++)
            printf("%2d",G->edges[i][j]);
        printf("\n");
    }
}

int main()
{
    MGrage G;
    Create(&G);
    return 0;
}
