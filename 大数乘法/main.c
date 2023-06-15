#include<stdio.h>
#include<string.h>
#define Max 1000
int main()
{
    char a[Max],b[Max];
    int c[Max],d[Max],e[Max];
    int a1,a2;
    int i,j;
    printf("please input the integer:\n");
    scanf("%s%s",a,b);
    a1=strlen(a);
    a2=strlen(b);
    int x=0;
    for(i=a1-1; i>=0; i--)
    {
        c[x]=a[i]-48;
        x++;
    }
    x=0;
    for(i=a2-1; i>=0; i--)
    {
        d[x]=b[i]-48;
        x++;
    }
    for(i=0; i<a1; i++)
    {
        for(j=0; j<a2; j++)
        {
            e[i+j]+=(c[i]*d[j]);
        }
    }
    for(j=0; j<Max; j++)
    {
        if(e[j]>=10)
        {
            e[j+1]+=e[j]/10;
            e[j]%=10;
        }
    }
    for(i=Max-1; i>=0; i--)
    {
        if(e[i]!=0)
            break;
        printf("%s * %s = ",a,b);
        for(; i>=0; i--)
        {
            printf("%d",e[i]);
        }
        printf("\n");
    return 0;
}
