#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MS 100
#define NA 16 //MS为线性表的最大长度

struct info
{
    char id[NA+1];      //学号
    char name[NA+1];       //姓名
};

typedef struct
{
    struct info data[MS];
    int length;					// length为线性表的长度
}SqList;
						//线性表定义
void InitList(SqList *L)			//初始化操作，将线性表L置空
{
    L->length=-1;
}
void CreatSqlist(SqList *L,int n)       //建立顺序表
{
    int i;
    for(i=0;i<n;i++)
    {
        L->length++;
        printf("输入第%d个学生学号:",i+1);
        scanf("%s",L->data[i].id);
        printf("输入此学生姓名:");
        scanf("%s",L->data[i].name);
        printf("--------------------");
    }
}

void LocateElem1(SqList *L,char idc[NA])       //按学号寻找学生姓名
{
    int k;
    for(k=0;k<L->length+1;k++)
    {
        if(strcmp(L->data[k].id,idc)==0)
        {
            printf("查询成功！\n");
            printf("学号：%s\n姓名：%s\n",idc,L->data[k].name);
            return;
        }
        printf("查询失败！");
    }

}

void LocateElem2(SqList *L,char na[NA])       //按姓名寻找学生学号
{
    int k;
    for(k=0;k<L->length+1;k++)
    {
        if(strcmp(L->data[k].name,na)==0)
        {
            printf("查询成功！\n");
            printf("学号：%s\n姓名：%s\n",L->data[k].id,na);
            return;
        }
        printf("查询失败！");
    }
}

void Output(SqList *L)      //显示通讯录所有学生信息
{
    int i;
    printf("     学号   ||    姓名\n");
    for(i=0;i<L->length+1;i++)
    {
        printf("    %s      \t%s\n",L->data[i].id,L->data[i].name);
    }
}

void Insert(SqList *L,int c)        //插入新学生
{
    int k;
    if(c<0||c>L->length+1||L->length==MS-1)
    {
        printf("插入失败！");
        return;
    }
    else
    {
        for(k=L->length+1;k>=c-1;k--)
        {
            strcpy(L->data[k].id,L->data[k-1].id);
            strcpy(L->data[k].name,L->data[k-1].name);
        }
        printf("输入插入学生的学号:");
        scanf("%s",L->data[c-1].id);
        printf("输入插入学生的姓名:");
        scanf("%s",L->data[c-1].name);
        L->length++;
    }
}

void Delete(SqList *L,int i)        //删除学生
{
    int k;
    if(i<0||i>=L->length)
    {
        printf("删除失败！");
        return;
    }
    else
    {
        for(k=i-1;k<L->length;k++)
        {
            strcpy(L->data[k].id,L->data[k+1].id);
            strcpy(L->data[k].name,L->data[k+1].name);
        }
        L->length--;
    }
}

void show()         //显示功能
{
    printf("\t1.建立通讯录\n");
    printf("\t2.查询信息\n");
    printf("\t3.插入新的信息\n");
    printf("\t4.删除信息\n");
    printf("\t5.显示所有信息\n");
    printf("\t6.结束\n");
    printf("\n");
}

int main()
{
    int ch;
    int a,c,d,i;
    int k;
    char id[NA],na[NA];
    int x;
    int f;      //选择指令
    SqList L;
    InitList(&L);
    fun: show();
    printf("请选择一项操作:");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
        case 1:
            {
                printf("建立通讯录\n");
                printf("输入通讯录成员个数:");
                scanf("%d",&a);
                CreatSqlist(&L,a);
                printf("通讯录成员为:\n");
                Output(&L);
                break;
            }
        case 2:
            {
                printf("1.按学号查找 2.按姓名查找\n");
                printf("请选择查找方式:");
                scanf("%d",&x);
                if(x==1)
                {
                    printf("请输入要查找学生的学号:");
                    scanf ("%s",&id);
                    LocateElem1(&L,id);
                }
                else if(x==2)
                {
                    printf("请输入要查找学生的姓名:");
                    scanf ("%s",na);
                    LocateElem2(&L,na);
                }
                else
                    break;
                break;
            }
        case 3:
                {
                    printf("输入要插入学生的位置:");
                    scanf ("%d",&c);
                    Insert(&L, c);
                    Output(&L);
                    printf("\n");
                    break;
                }
        case 4:
                {
                    printf ("输入要删除学生的位置:");
                    scanf ("%d",&i);
                    Delete(&L,i);
                    Output(&L);
                    break;
                }
        case 5:
                {
                    Output(&L);
                    break;
                }
        case 6:
                {
                    return 0;
                }
    }
    printf("\n");
    printf("----------------------\n");
    printf("1.继续运行     2.结束:\n");
    scanf("%d",&f);
    if (f==2)
        return 0;
    else if(f==1)
        goto fun;
}






