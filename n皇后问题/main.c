#include <stdio.h>
#include <stdlib.h>

int n;  //n皇后
int x[100]; //解数组

void initial()
{
    int i;
    printf("请输入皇后个数:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        x[i]=0;
}

void Queen(int n)
{
    int count=0;
    int k=1;
    while(k>=1)
    {
        x[k]=x[k]+1;
        while(x[k]<=n&&(!place(k)))
            x[k]=x[k]+1;
        if(k==n&&x[k]<=n)
        {
            count++;
            printf("\n");
            print(x);
        }
        else if(k<n&&x[k]<=n)
            k=k+1;
        else
        {
            x[k]=0;
            k=k-1;
        }
    }
    printf("\n方案个数为:%3d",count);
}

int place(int k)
{
    int i;
    for(i=1;i<k;i++)
        if(x[i]==x[k]||abs(i-k)==abs(x[i]-x[k]))
            return 0;
    return 1;
}

void print(int x[])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==x[i])
                printf(" Q");
            else
                printf(" X");
        }
        printf("\n");
    }
}

int main()
{
    initial();
    Queen(n);
    return 0;
}
