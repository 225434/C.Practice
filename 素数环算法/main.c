#include <stdio.h>
#include <stdlib.h>

int n;
int a[100];
int x[100];
int count=0;

void initial()
{
    int i;
    printf("请输入素数环的节点数:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        x[i]=0;
        a[i]=0;
    }
}

int chick(int num)
{
    if((num==2||num==3)||(num>3)&&(num%6==1||num%6==5))
        return 1;
    return 0;
}

void ring(int step)
{
    int i,j;
    if(step==n&&chick(a[n]+a[1])==1)
    {
        count++;
        for(i=1;i<=n;i++)
            printf("%3d",a[i]);
        printf("\n");
        return;
    }
    else
    {
        for(j=2;j<=n;j++)
        {
            if(x[j]==0&&chick(a[step]+j))
            {
                a[step+1]=j;
                x[j]=1;
                ring(step+1);
                x[j]=0;
            }
        }
    }
    return;
}

int main()
{
    int i;
    initial();
    a[1]=1;
    x[1]=1;
    ring(1);
    printf("素数环数量为:%3d",count);
    return 0;
}
