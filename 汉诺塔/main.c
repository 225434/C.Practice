#include <stdio.h>
#include <stdlib.h>

void hanio(int n,char A,char B,char C)
{
    if(n==1)
        printf("%c->%c\n",A,C);

    else
    {
        hanio(n-1,A,C,B);
        printf("%c->%c\n",A,C);
        hanio(n-1,B,A,C);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    hanio(n,'A','B','C');
    return 0;
}
