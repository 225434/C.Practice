#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i,j;
    int max;
    printf("输入层高:");
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    for(i=0;i<n;i++)
    {
        printf("输入第%d行的数:",i+1);
        for(j=0;j<i+1;j++)
        {
            scanf("%d",&a[i][j]);
            c[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[i][j]=0;
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<i+1;j++)
        {
            if(a[i+1][j]>a[i+1][j+1])
                b[i+1][j]=1;
            else if(a[i+1][j]<a[i+1][j+1])
                b[i+1][j+1]=1;
            else
            {
                b[i+1][j]=1;
                b[i+1][j+1]=1;
            }
            a[i][j]+=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];
        }
    }
    printf("%d\n",a[0][0]);
    printf("%2d->",c[0][0]);
    int mark=0;
    for(i=1;i<n;i++)
    {
        j=mark;
        while(j<i)
        {
            if(b[i][j]==1&&b[i][j+1]!=1)
            {
                printf("%2d->",c[i][j]);
                break;
            }
            else if(b[i][j]!=1&&b[i][j+1]==1)
            {
                mark++;
                printf("%2d->",c[i][j+1]);
                break;
            }
            else
            {
                if(a[i][j]>a[i][j+1])
                {
                    mark++;
                    printf("%2d->",c[i][j]);
                    break;
                }
                if(a[i][j]<a[i][j+1])
                {
                    mark++;
                    printf("%2d->",c[i][j+1]);
                    break;
                }
            }
        }
    }
    printf("结束");
    return 0;
}
