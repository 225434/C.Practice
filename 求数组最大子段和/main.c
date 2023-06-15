#include <stdio.h>
#include <stdlib.h>

int maxnum(int a[],int left,int right)
{
    printf("lift:%3d\tright:%3d\n",left,right);
    int center,lsum,rsum,s1,s2,ls,rs;
    int i;
    if(left==right)
    {
        if(a[left]>0)
            return a[left-1];
        else
            return 0;
    }
    else
    {
        center=(left+right)/2;
        lsum=maxnum(a,left,center);
        rsum=maxnum(a,center+1,right);
        ls=0; s1=0;
        for(i=center;i>=left;i--)
        {
            ls+=a[i-1];
            if(s1<ls)
                s1=ls;
        }
        rs=0;s2=0;
        for(i=center+1;i<=right;i++)
        {
            rs+=a[i-1];
            if(s2<rs)
                s2=rs;
        }
        if((s1+s2<lsum)&&(rsum<lsum))
            return lsum;
        if(s1+s2<rsum)
            return rsum;
        return s1+s2;
    }
}

int main()
{
    int a[6]={12,11,-4,3,-5,-2},n=6;
    printf("\n\tsum=%3d\n\n",maxnum(a,1,n));
    return 0;
}
