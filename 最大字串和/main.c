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
    printf("����Ӷ�Ϊ:%d��%d\n",l+1,r+1);
    return sum;
}

int main()
{
    int n;
    printf("��������Ԫ�ظ���:");
    scanf("%d",&n);
    int a[n];
    printf("��������Ԫ��:");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int sum=found(a,n,l,r);
    printf("����Ӷκ�Ϊ:%3d",sum);
    return 0;
}
