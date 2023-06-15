#include <stdio.h>
#include <stdlib.h>

int fun(int a,int b)
{
    return b==0?a:fun(b,a%b);
}

int main()
{
    printf("input the number:");
    int a,b;
    scanf("%d%d",&a,&b);
    int r=fun(a,b);
    printf("%d",r);
    return 0;
}
