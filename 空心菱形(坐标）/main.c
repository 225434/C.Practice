#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print(int n)
{
    int x,y;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            if((x+y==n/2)||(x+y==3*n/2-1)||(abs(x-y)==n/2)||(abs(x-y)==3*n/2-1))
                printf("#");
            else
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("input the hight:");
    scanf("%d",&n);
    while(n%2==0)
    {
        printf("please input a odd number:");
        scanf("%d",&n);
    }
    print(n);
    return 0;
}
