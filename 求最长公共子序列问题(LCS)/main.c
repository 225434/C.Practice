#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)(a>b?a:b)


int c[200][200];
int b[200][200];
char f[200];

void print(int i,int j,int s,char x[],char y[])
{
    if(b[i][j]==1)
    {
        f[s-1]=x[i-1];
        i--;
        j--;
        s--;
        print(i,j,s,x,y);
    }
    else if(b[i][j]==3)
    {
        i--;
        print(i,j,s,x,y);
    }
    else if(b[i][j]==2)
    {
        j--;
        print(i,j,s,x,y);
    }
}

int lcs(char x[],char y[])
{
    int i,j;
    int xlen=strlen(x),ylen=strlen(y);
    printf("   ");
    for(i=0;i<ylen;i++)
    {
        printf("%c  ",y[i]);
    }
    printf("\n");
    for(i=1;i<=xlen;i++)
    {
        printf("%c  ",x[i-1]);
        for(j=1;j<=ylen;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                printf("%d  ",c[i][j]);
            }
            else
            {
                c[i][j]=MAX(c[i][j-1],c[i-1][j]);
                printf("%d  ",c[i][j]);
            }
            if(x[i]==y[j])
                b[i][j]=1;
            else if(c[i-1][j]>=c[i][j-1])
                b[i][j]=2;
            else
                b[i][j]=3;
        }
        printf("\n");
    }
    printf("x和y的lcs是:");
    print(xlen,ylen,c[xlen][ylen],x,y);
    printf("%s",f);
    printf("\n");
    return c[xlen][ylen];
}

int main()
{
    int s;
    char x[200];
    char y[200];
    printf("请输入x字符串:");
    scanf("%s",&x);
    printf("请输入y字符串:");
    scanf("%s",&y);
    s=lcs(x,y);
    printf("x和y的lcs为:%3d",s);
    return 0;
}
