#include <iostream>
#include <algorithm>
using namespace std;
typedef struct LinkTable *PtoLT;
typedef struct LinkTable{
	int Data;
	PtoLT Next;
}LT;

void CreatLinkTable(PtoLT &List);			//创建单链表 
void InsertElement(PtoLT &head);			//头插法插入n个元素。注：我不清楚头插法头指针存不存放数据，为了便于实现，我没有按惯例让头指针数据为空，而是用它存放了数据，序号为0 
void DeleteElement(PtoLT &head);			//删除第i个元素 
void SearchbyKey(PtoLT head);				//按关键字查找单链表 
void Print(PtoLT head);						//计算表长并输出单链表 
void DestroyLinkTable(PtoLT &head);			//销毁单链表 

int main()	{
	int n=1;
	PtoLT List=(PtoLT)malloc(sizeof(LT));
	printf("**********************************\n");
	printf("**	1.创建单链表		**\n");
	printf("**	2.头插法插入n个元素	**\n");
	printf("**	3.删除第i个元素		**\n");
	printf("**	4.按关键字查找单链表	**\n");
	printf("**	5.计算表长并输出单链表	**\n"); 
	printf("**	6.销毁单链表		**\n");
	printf("**********************************\n\n");
	while (n)	{
		point:;
		printf("请输入你的选择：	");
		scanf("%d",&n);
		switch(n)	{
			case 1:	{ 								//创建一个新的单链表 
				List=(PtoLT)malloc(sizeof(LT));
				CreatLinkTable(List);break;
			}
			case 2:	InsertElement(List);break;		//插入元素 
			case 3:	DeleteElement(List);break;		//删除元素 
			case 4:	SearchbyKey(List);break;		//查找元素 
			case 5:	Print(List);break;				//打印表长和所有元素值 
			case 6:	DestroyLinkTable(List);break;	//销毁线性表 
			default:	printf("请重新输入!\n");goto point;
		}
	}
	return 0;
}

void CreatLinkTable(PtoLT &List)	{
	List->Next=NULL;
	List->Data=-1;
	printf("创建成功！\n");
}

void InsertElement(PtoLT &head)	{
	int times,t=0;
	printf("请输入要插入的数据个数：");
	scanf("%d",&times);
	while (t++,times--)	{
		int temp;
		PtoLT TP=(PtoLT)malloc(sizeof(LT));
		printf("请输入要插入的第%d个数据：",t);
		scanf("%d",&temp);
		TP->Data=temp;
		TP->Next=head;
		head=TP;
	}
	printf("插入成功！\n");
}

void DeleteElement(PtoLT &head)	{
	int i;
	printf("请输入你要删除的元素序号：");
	scanf("%d",&i);
	PtoLT TP=head;
	while (i-1>0)	
		i--,TP=TP->Next;
	PtoLT TP0=TP->Next;
	TP->Next=TP0->Next;
	free(TP0);
	printf("删除成功！\n");
}

void SearchbyKey(PtoLT head)	{
	int key,des=0;
	printf("请输入要查找的关键字：");
	scanf("%d",&key);
	while (head!=NULL)	{
		if (head->Data!=key)
			++des,head=head->Next;
		else	break;
	}
	if (head!=NULL)
		printf("位置：%d	数据：%d\n",des,key);
	else
		printf("查无此元素！\n");
}

void Print(PtoLT head)	{
	if (!head)	{
		printf("链表为空！\n");
		return;
	}
	int len=0;
	PtoLT TP=head;
	while (TP->Next!=NULL)	{
		printf("%d",TP->Data),len++;
		if (TP->Next->Next!=NULL)	printf(" ");
		else printf("\n");
		TP=TP->Next;
	}
	printf("单链表长度：%d\n",len);
}

void DestroyLinkTable(PtoLT &head)	{
	while (head!=NULL)	{
		PtoLT T0=head;
		head=head->Next;
		free(T0);
	}
	printf("销毁成功！\n");
}



