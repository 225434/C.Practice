#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f;
    for(a=0;a<=1;a++)
    {
        for(b=0;b<=1;b++)
        {
            for(c=0;c<=1;c++)
            {
                for(d=0;d<=1;d++)
                {
                    for(e=0;e<=1;e++)
                    {
                        for(f=0;f<=1;f++)
                        {
                            if((a+b!=0)&&((a+e+f)>=2)&&((a+d)!=2)&&((c+d)==1)&&((b+c)!=1)&&((d+e)==0))
                            {
                                printf("%3d%3d%3d%3d%3d%3d",a,b,c,d,e,f);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
