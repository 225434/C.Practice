#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int tile=1;
int Board[100][100];

void TileBoard(int tr,int tc,int dr,int dc,int size)
{
  if(size==1)
    return;
  int t=tile++;
  int s=size/2;
  if(dr<tr+s&&dc<tc+s)
    TileBoard(tr,tc,dr,dc,s);
  else
  {
    Board[tr+s-1][tc+s-1]=t;
    TileBoard(tr,tc,tr+s-1,tc+s-1,s);
  }

  if(dr<tr+s&&dc>=tc+s)
    TileBoard(tr,tc+s,dr,dc,s);
  else
  {
    Board[tr+s-1][tc+s]=t;
    TileBoard(tr,tc+s,tr+s-1,tc+s,s);
  }

  if(dr>=tr+s&&dc<tc+s)
    TileBoard(tr+s,tc,dr,dc,s);
  else
  {
    Board[tr+s][tc+s-1]=t;
    TileBoard(tr+s,tc,tr+s,tc+s-1,s);
  }

  if(dr>=tr+s&&dc>=tc+s)
    TileBoard(tr+s,tc+s,dr,dc,s);
  else
  {
    Board[tr+s][tc+s]=t;
    TileBoard(tr+s,tc+s,tr+s,tc+s,s);
  }
}

void output(int size)
{
  int i,j;
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
      printf("%-3d",Board[i][j]);
    printf("\n");
  }
}

int main()
{
    int n,a,b;
    printf("input the num:");
    scanf("%d",&n);
    int sum;
    sum=pow(2,n);
    scanf("%d%d",&a,&b);
    Board[sum-a-1][b-1]=0;
    TileBoard(0,0,a-1,b-1,sum);
    output(sum);
    return 0;
}
