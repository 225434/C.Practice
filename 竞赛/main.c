#include <stdio.h>
#include <stdlib.h>

int f(int a,int b)
{
    return a==b?1:0;
}

int ff(int a,int b,int c,int d,int e)
{
    int i,j;
    int n[5]={a,b,c,d,e};
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(n[i]==n[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int a,b,c,d,e;
    for(a=1;a<=5;a++)
        for(b=1;b<=5;b++)
            for(c=1;c<=5;c++)
                for(d=1;d<=5;d++)
                    for(e=1;e<=5;e++)
                        if(((f(b,3)+f(c,5))==1)&&((f(d,2)+f(e,4))==1)&&((f(b,1)+f(e,4))==1)&&((f(c,1)+f(b,2))==1)&&((f(d,2)+f(a,3))==1))
                            if(ff(a,b,c,d,e)==1)
                                printf("%3d%3d%3d%3d%3d\n",a,b,c,d,e);
    return 0;
}
