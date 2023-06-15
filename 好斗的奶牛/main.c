#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,C,f[100];
    printf("输入奶牛数和房间数:")
    scanf("%d%d",&N,&C);
    int i;
    printrf("输入房间号:");
    for(i=0;i<N;i++)
        scanf("%d",&f[i]);
    int j,temp;
    for(i=1;i<N;i++)
    {
        if(f[i]<f[i-1])
        {
            temp=f[i];
            for(j=i-1;j>=0&&temp<f[j];j--)
                f[j+1]=f[j];
            f[j+1]=temp;
        }
    }
    int left=0,right,mid,dex,num;
    int c=C-1;
    mid=right=(f[N-1]-f[0])/2;
    while(left<right)
    {
        dex=0;
        num=0;
        for(i=dex+1;i<N;i++)
        {
            if((f[i]-f[dex])>mid)
            {
                dex=i;
                num++;
                if(num==c)
                    break;
            }
        }
        if(i==N)
            right=mid-1;
        else
            left=mid;
        mid=(left+right+1)/2;
    }
    printf("%d",mid+1);
    return 0;
}
