#include <stdio.h>
#include <stdlib.h>

int n;  //��װ����
int c1;  //��һ�Ҵ�������
int c2; //�ڶ��Ҵ�������
int r;  //ʣ�༯װ������
int cw; //��ǰ������
int bestw; //��ǰ����������
int w[100]; //��װ������
int x[100]; //��ǰ��
int bestx[100]; //��ǰ���Ž�

void input()
{
    int i;
    printf("���뼯װ����:");
    scanf("%d",&n);
    printf("�����һ�Ҵ��͵ڶ��Ҵ���������:");
    scanf("%d %d",&c1,&c2);
    printf("�������װ������:");
    for(i=1;i<=n;++i)
        scanf("%d",&w[i]);
}

void initial()
{
    int i;
    bestw=0;
    cw=0;
    r=0;
    for(i=1;i<=n;i++)
        r+=w[i];
}

void BackTrack(int a)
{
    int i;
    if(a>n)
    {
        if(cw>bestw)
        {
            for(i=1;i<=n;i++)
                bestx[i]=x[i];
            bestw=cw;

        }
        return;
    }
    r-=w[a];
    if(cw+w[a]<=c1)
    {
        x[a]=1;
        cw+=w[a];
        BackTrack(a+1);
        x[a]=0;
        cw-=w[a];
    }
    if(cw+r>bestw)
    {
        x[a]=0;
        BackTrack(a+1);
    }
    r+=w[a];
}

void display()
{
    int rw=0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(bestx[i]==0)
            rw+=w[i];
    }
    if(rw>c2)
        printf("�޷�װ�룡");
    else
    {
        printf("װ���һ�Ҵ��ļ�װ������Ϊ:");
        for(i=1;i<=n;i++)
            if(bestx[i]==1)
                printf("%3d",w[i]);
        printf("\n");
        printf("װ��ڶ��Ҵ��ļ�װ������Ϊ:");
        for(i=1;i<=n;i++)
            if(bestx[i]!=1)
                printf("%3d",w[i]);
    }
}

void m()
{
    printf("shiohva");
}

int main()
{
    input();
    initial();
    BackTrack(1);
    display();
    return 0;
}
