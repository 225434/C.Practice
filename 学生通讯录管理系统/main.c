#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MS 100
#define NA 16 //MSΪ���Ա����󳤶�

struct info
{
    char id[NA+1];      //ѧ��
    char name[NA+1];       //����
};

typedef struct
{
    struct info data[MS];
    int length;					// lengthΪ���Ա�ĳ���
}SqList;
						//���Ա���
void InitList(SqList *L)			//��ʼ�������������Ա�L�ÿ�
{
    L->length=-1;
}
void CreatSqlist(SqList *L,int n)       //����˳���
{
    int i;
    for(i=0;i<n;i++)
    {
        L->length++;
        printf("�����%d��ѧ��ѧ��:",i+1);
        scanf("%s",L->data[i].id);
        printf("�����ѧ������:");
        scanf("%s",L->data[i].name);
        printf("--------------------");
    }
}

void LocateElem1(SqList *L,char idc[NA])       //��ѧ��Ѱ��ѧ������
{
    int k;
    for(k=0;k<L->length+1;k++)
    {
        if(strcmp(L->data[k].id,idc)==0)
        {
            printf("��ѯ�ɹ���\n");
            printf("ѧ�ţ�%s\n������%s\n",idc,L->data[k].name);
            return;
        }
        printf("��ѯʧ�ܣ�");
    }

}

void LocateElem2(SqList *L,char na[NA])       //������Ѱ��ѧ��ѧ��
{
    int k;
    for(k=0;k<L->length+1;k++)
    {
        if(strcmp(L->data[k].name,na)==0)
        {
            printf("��ѯ�ɹ���\n");
            printf("ѧ�ţ�%s\n������%s\n",L->data[k].id,na);
            return;
        }
        printf("��ѯʧ�ܣ�");
    }
}

void Output(SqList *L)      //��ʾͨѶ¼����ѧ����Ϣ
{
    int i;
    printf("     ѧ��   ||    ����\n");
    for(i=0;i<L->length+1;i++)
    {
        printf("    %s      \t%s\n",L->data[i].id,L->data[i].name);
    }
}

void Insert(SqList *L,int c)        //������ѧ��
{
    int k;
    if(c<0||c>L->length+1||L->length==MS-1)
    {
        printf("����ʧ�ܣ�");
        return;
    }
    else
    {
        for(k=L->length+1;k>=c-1;k--)
        {
            strcpy(L->data[k].id,L->data[k-1].id);
            strcpy(L->data[k].name,L->data[k-1].name);
        }
        printf("�������ѧ����ѧ��:");
        scanf("%s",L->data[c-1].id);
        printf("�������ѧ��������:");
        scanf("%s",L->data[c-1].name);
        L->length++;
    }
}

void Delete(SqList *L,int i)        //ɾ��ѧ��
{
    int k;
    if(i<0||i>=L->length)
    {
        printf("ɾ��ʧ�ܣ�");
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

void show()         //��ʾ����
{
    printf("\t1.����ͨѶ¼\n");
    printf("\t2.��ѯ��Ϣ\n");
    printf("\t3.�����µ���Ϣ\n");
    printf("\t4.ɾ����Ϣ\n");
    printf("\t5.��ʾ������Ϣ\n");
    printf("\t6.����\n");
    printf("\n");
}

int main()
{
    int ch;
    int a,c,d,i;
    int k;
    char id[NA],na[NA];
    int x;
    int f;      //ѡ��ָ��
    SqList L;
    InitList(&L);
    fun: show();
    printf("��ѡ��һ�����:");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
        case 1:
            {
                printf("����ͨѶ¼\n");
                printf("����ͨѶ¼��Ա����:");
                scanf("%d",&a);
                CreatSqlist(&L,a);
                printf("ͨѶ¼��ԱΪ:\n");
                Output(&L);
                break;
            }
        case 2:
            {
                printf("1.��ѧ�Ų��� 2.����������\n");
                printf("��ѡ����ҷ�ʽ:");
                scanf("%d",&x);
                if(x==1)
                {
                    printf("������Ҫ����ѧ����ѧ��:");
                    scanf ("%s",&id);
                    LocateElem1(&L,id);
                }
                else if(x==2)
                {
                    printf("������Ҫ����ѧ��������:");
                    scanf ("%s",na);
                    LocateElem2(&L,na);
                }
                else
                    break;
                break;
            }
        case 3:
                {
                    printf("����Ҫ����ѧ����λ��:");
                    scanf ("%d",&c);
                    Insert(&L, c);
                    Output(&L);
                    printf("\n");
                    break;
                }
        case 4:
                {
                    printf ("����Ҫɾ��ѧ����λ��:");
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
    printf("1.��������     2.����:\n");
    scanf("%d",&f);
    if (f==2)
        return 0;
    else if(f==1)
        goto fun;
}






