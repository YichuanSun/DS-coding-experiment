#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100	//���Ա��ʼ������ 
#define LISTINCREMENT 2		//�洢�ռ�������� 
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;		//�洢�ռ��ַ 
	int lenth;			//���Ա�ǰ�Ĵ�С 
	int listsize;		//��ǰ����Ĵ洢���� 
}SqList;

Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList &L,int i,ElemType e);
Status ListDelet_Sq(SqList &L,int i,ElemType &e);
int LocateElem_Sq(SqList L,ElemType e);
int DestroyList(SqList &L);
void print(SqList &L);

Status InitList_Sq(SqList &L)	{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem){
		printf("����ʧ��,�����´�����\n");
		exit(OVERFLOW);
	}	
	L.lenth=0;
	L.listsize=LIST_INIT_SIZE;
	printf("�����ɹ���\n");
	return OK;
}

void mainmenu()
//����˵�
{
	printf("\n		�˵�");
	printf("\n***********************\n\n");
	printf("*	1.��������		*\n");
	printf("*	2.�����		*\n");
	printf("*	3.����Ԫ��		*\n");
	printf("*	4.ɾ��Ԫ��		*\n");
	printf("*	5.����Ԫ��		*\n");
	printf("*	6.�������Ա�		*\n");
	printf("*	0.�˳�			*\n");
} 

int main()	{
	int choose;
	SqList La;
	mainmenu();
	while(1)	{
		printf("\n 	���������ѡ�� ");
		scanf("%d",&choose);
		switch(choose)	{
			case 1:	InitList_Sq(La);break;
			case 2:	print(La);break;
			case 3:	{
				int i,e; 
				printf("������Ҫ�����λ�ã�");
				scanf("%d",&i);
				printf("������Ҫ��������ݣ�"); 
				scanf("%d",&e);
				ListInsert_Sq(La,i,e);
				break;
			}
			case 4:	{
				int i,e;
				printf("������Ҫɾ����λ�ã�");
				scanf("%d",&i);
				printf("������Ҫɾ����λ���ϵ����ݣ�");
				scanf("%d",&e);
				ListDelet_Sq(La,i,e);
				break;
			}
			case 5:	{
				int e;
				printf("������Ҫ��ѯ�����ݣ�");
				scanf("%d",&e);
				printf("Ҫ��ѯ��������%dλ��",LocateElem_Sq(La,e)+1);
				break;
			}
			case 6:	DestroyList(La);break;
			case 0:	exit(0);break;
			default:	printf("\n��������������룡\n");
		}
	}
	return 0;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e)	{
	if (i<1||i>L.lenth+1)	
	{
		printf("����ʧ��!\n"); 
		return ERROR;
	}
	if (L.lenth>=L.listsize)	{
		ElemType* newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)	exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	ElemType* q=&(L.elem[i-1]);
	for (ElemType* p=&(L.elem[L.lenth-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.lenth;
	printf("����ɹ���\n");
	return OK;
}

Status ListDelet_Sq(SqList &L,int i,ElemType &e)	{
	if (i<1||i>L.lenth)	
	{
		printf("ɾ��ʧ��!\n"); 
		return ERROR;
	}
	ElemType* p=&(L.elem[i-1]);
	e=*p;
	ElemType* q=L.elem+L.lenth-1;
	for (++p;p<=q;++p)	*(p-1)=*p;
	--L.lenth;
	printf("ɾ���ɹ���\n");
	return OK;
}

int LocateElem_Sq(SqList L,ElemType e)	{
	int i=0;
	ElemType* p=L.elem;
	while (i<=L.lenth&&(*p++)!=e)	i++;
	if (i<=L.lenth)	return i;
	else	return 0;
}

int DestroyList(SqList &L)	{
	ElemType* p=L.elem;
	free(p);
	L.elem=NULL; 
	//ElemType* q=L.elem+L.lenth-1;
	//for (++p;p<=q;++p)	free(L);
	printf("���ٳɹ���\n"); 
	return 0;
}

void print(SqList &L){
	ElemType* p=L.elem;
	if (!p){
		printf("���Ա�Ϊ�գ�\n");
		return;
	}
	ElemType* q=L.elem+L.lenth-1;
	for (;p<=q;++p)	printf("%d ",*p);
}
