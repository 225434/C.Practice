#include <stdio.h>
#include <stdlib.h>

int l=0,r=0;

int found(int a[],int n,int l,int r)
{
    int sum=0,b=0,begin;
    int i;
    for(i=0;i<n;i++)
    {
        if(b>0)
            b+=a[i];
        else
        {
            b=a[i];
            begin=i;
        }
        if(b>sum)
        {
            sum=b;
            l=begin;
            r=i;
        }
    }
    printf("最大子段为:%d到%d\n",l+1,r+1);
    return sum;
}

int main()
{
    int n;
    printf("输入数组元素个数:");
    scanf("%d",&n);
    int a[n];
    printf("输入数组元素:");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int sum=found(a,n,l,r);
    printf("最大子段和为:%3d",sum);
    return 0;
}
