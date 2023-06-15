#include <stdio.h>
#include <stdlib.h>

void rank(int a[],int l)
{
    int i,j,temp;
    for(i=1;i<=l;i++)
    {
        if(a[i]<a[i-1])
        {
            temp=a[i];
            for(j=i-1;a[j]>temp&&j>=0;j--)
                a[j+1]=a[j];
            a[j+1]=temp;
        }
    }
}

int main()
{
    int a[100]={5,2,55,655,63,64,55,12,3};
    int i;
    rank(a,9);
    for(i=0;i<9;i++)
        printf("%4d",a[i]);
    return 0;
}
