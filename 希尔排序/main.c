#include <stdio.h>
#include <stdlib.h>

void shell(int a[],int l)
{
    int i,j,k,gap,temp;
    for(gap=l/2;gap>0;gap/=2)
    {
        for(i=0;i<gap;i++)
        {
            for(j=gap+i;j<l;j+=gap)
            {
                temp=a[j];
                k=j-gap;
                while(k>=0&&a[k]>temp)
                {
                    a[k+gap]=a[k];
                    k-=gap;
                }
                a[k+gap]=temp;
            }
        }
    }
}

int main()
{
    int a[100]={5,2,55,655,63,64,55,12,3,22};
    int i;
    shell(a,10);
    for(i=0;i<10;i++)
        printf("%4d",a[i]);
    return 0;
}
