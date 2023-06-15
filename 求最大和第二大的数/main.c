#include<stdio.h>

void pick(int a[],int low,int high)
{
    if(low>high)
        return;
    int i=low,j=high,temp=a[i];
    while(i<j)
    {
        while(temp<a[j]&&i<j)
            j--;
        if(i<j)
            a[i++]=a[j];
        while(temp>a[i]&&i<j)
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=temp;
    pick(a,low,i-1);
    pick(a,i+1,high);
}

int main()
{
    int a[100];
    int i,n;
    printf("�������������");
    scanf("%d",&n);
    printf("�������飺");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    pick(a,0,n);
    printf("\n���͵ڶ������Ϊ%3d ��%3d",a[n-1],a[n-2]);
    return 0;
}
