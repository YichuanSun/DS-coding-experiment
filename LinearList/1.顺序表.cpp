#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100	//线性表初始分配量 
#define LISTINCREMENT 2		//存储空间分配增量 
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;		//存储空间基址 
	int lenth;			//线性表当前的大小 
	int listsize;		//当前分配的存储容量 
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
		printf("创建失败,请重新创建！\n");
		exit(OVERFLOW);
	}	
	L.lenth=0;
	L.listsize=LIST_INIT_SIZE;
	printf("创建成功！\n");
	return OK;
}

void mainmenu()
//输出菜单
{
	printf("\n		菜单");
	printf("\n***********************\n\n");
	printf("*	1.建立链表		*\n");
	printf("*	2.输出表		*\n");
	printf("*	3.插入元素		*\n");
	printf("*	4.删除元素		*\n");
	printf("*	5.查找元素		*\n");
	printf("*	6.销毁线性表		*\n");
	printf("*	0.退出			*\n");
} 

int main()	{
	int choose;
	SqList La;
	mainmenu();
	while(1)	{
		printf("\n 	请输入你的选择： ");
		scanf("%d",&choose);
		switch(choose)	{
			case 1:	InitList_Sq(La);break;
			case 2:	print(La);break;
			case 3:	{
				int i,e; 
				printf("输入你要插入的位置：");
				scanf("%d",&i);
				printf("输入你要插入的数据："); 
				scanf("%d",&e);
				ListInsert_Sq(La,i,e);
				break;
			}
			case 4:	{
				int i,e;
				printf("输入你要删除的位置：");
				scanf("%d",&i);
				printf("输入你要删除的位置上的数据：");
				scanf("%d",&e);
				ListDelet_Sq(La,i,e);
				break;
			}
			case 5:	{
				int e;
				printf("输入你要查询的数据：");
				scanf("%d",&e);
				printf("要查询的数据在%d位置",LocateElem_Sq(La,e)+1);
				break;
			}
			case 6:	DestroyList(La);break;
			case 0:	exit(0);break;
			default:	printf("\n输入错误，重新输入！\n");
		}
	}
	return 0;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e)	{
	if (i<1||i>L.lenth+1)	
	{
		printf("插入失败!\n"); 
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
	printf("插入成功！\n");
	return OK;
}

Status ListDelet_Sq(SqList &L,int i,ElemType &e)	{
	if (i<1||i>L.lenth)	
	{
		printf("删除失败!\n"); 
		return ERROR;
	}
	ElemType* p=&(L.elem[i-1]);
	e=*p;
	ElemType* q=L.elem+L.lenth-1;
	for (++p;p<=q;++p)	*(p-1)=*p;
	--L.lenth;
	printf("删除成功！\n");
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
	printf("销毁成功！\n"); 
	return 0;
}

void print(SqList &L){
	ElemType* p=L.elem;
	if (!p){
		printf("线性表为空！\n");
		return;
	}
	ElemType* q=L.elem+L.lenth-1;
	for (;p<=q;++p)	printf("%d ",*p);
}
