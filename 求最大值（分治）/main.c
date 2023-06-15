#include <stdio.h>
#include <stdlib.h>

int a[100]={11,10,121,54,3,54,31631,31,99};

int maxx(int i,int j,int *max,int *min)
{
    int center;
    int lmax,lmin,rmax,rmin;
    if(i==j)
    {
        *max=a[i];
        *min=a[i];
    }
    else if(i==j-1)
    {
        *max=a[i]>a[j]?a[i]:a[j];
        *min=a[i]<a[j]?a[i]:a[j];
    }
    else
    {
        center=(i+j)/2;
        *max=maxx(i,center,&lmax,&lmin);
        *min=maxx(center+1,j,&rmax,&rmin);
        if(lmax>rmax)
            *max=lmax;
        else
            *max=rmax;
        if(lmin<rmin)
            *min=lmin;
        else
            *min=rmin;
    }
}

int main()
{
    int max,min;
    maxx(0,8,&max,&min);
    printf("max=%2d,min=%2d",max,min);
    return 0;
}
