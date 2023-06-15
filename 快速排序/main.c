#include <stdio.h>
#include <stdlib.h>

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
    int a[100]={5,2,55,655,63,64,55,12,3};
    int i;
    pick(a,0,8);
    for(i=0;i<9;i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}
