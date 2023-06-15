#include <stdio.h>
#include <stdlib.h>

int P(int i)
{
    return i==1||i==2?1:P(i-1)+P(i-2);
}

int main()
{
    printf("求第n个数：");
    int i;
    scanf("%d",&i);
    printf("%3d",P(i));
    return 0;
}
