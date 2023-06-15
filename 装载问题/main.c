#include <stdio.h>
#include <stdlib.h>

int n;  //集装箱数
int c1;  //第一艘船载重量
int c2; //第二艘船载重量
int r;  //剩余集装箱重量
int cw; //当前载重量
int bestw; //当前最优载重量
int w[100]; //集装箱重量
int x[100]; //当前解
int bestx[100]; //当前最优解

void input()
{
    int i;
    printf("输入集装箱数:");
    scanf("%d",&n);
    printf("输入第一艘船和第二艘船的载重量:");
    scanf("%d %d",&c1,&c2);
    printf("输入各集装箱重量:");
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
        printf("无法装入！");
    else
    {
        printf("装入第一艘船的集装箱重量为:");
        for(i=1;i<=n;i++)
            if(bestx[i]==1)
                printf("%3d",w[i]);
        printf("\n");
        printf("装入第二艘船的集装箱重量为:");
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
