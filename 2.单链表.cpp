#include <iostream>
#include <algorithm>
using namespace std;
typedef struct LinkTable *PtoLT;
typedef struct LinkTable{
	int Data;
	PtoLT Next;
}LT;

void CreatLinkTable(PtoLT &List);
void InsertElement(PtoLT &head);
void DeleteElement(PtoLT &head);
void SearchbyKey(PtoLT head);
void Print(PtoLT head);
void destroyLinkTable(PtoLT &head);

int main()	{
	int n=1;
	PtoLT List=(PtoLT)malloc(sizeof(LT));
	printf("**********************************\n");
	printf("**	1.����������		**\n");
	printf("**	2.ͷ�巨����n��Ԫ��	**\n");
	printf("**	3.ɾ����i��Ԫ��		**\n");
	printf("**	4.���ؼ��ֲ��ҵ�����	**\n");
	printf("**	5.����������������	**\n"); 
	printf("**	6.���ٵ�����		**\n");
	printf("**********************************\n\n");
	while (n)	{
		point:;
		printf("���������ѡ��	");
		scanf("%d",&n);
		switch(n)	{
			case 1:	{
				List=(PtoLT)malloc(sizeof(LT));
				CreatLinkTable(List);break;
			}
			case 2:	InsertElement(List);break;
			case 3:	DeleteElement(List);break;
			case 4:	SearchbyKey(List);break;
			case 5:	Print(List);break;
			case 6:	destroyLinkTable(List);break;
			default:	printf("����������!\n");goto point;
		}
	}
	return 0;
}

void CreatLinkTable(PtoLT &List)	{
	List->Next=NULL;
	List->Data=-1;
	printf("�����ɹ���\n");
}

void InsertElement(PtoLT &head)	{
	int times,t=0;
	printf("������Ҫ��������ݸ�����");
	scanf("%d",&times);
	while (t++,times--)	{
		int temp;
		PtoLT TP=(PtoLT)malloc(sizeof(LT));
		printf("������Ҫ����ĵ�%d�����ݣ�",t);
		scanf("%d",&temp);
		TP->Data=temp;
		TP->Next=head;
		head=TP;
	}
	printf("����ɹ���\n");
}

void DeleteElement(PtoLT &head)	{
	int i;
	printf("��������Ҫɾ����Ԫ����ţ�");
	scanf("%d",&i);
	PtoLT TP=head;
	while (i-1>0)	
		i--,TP=TP->Next;
	PtoLT TP0=TP->Next;
	TP->Next=TP0->Next;
	free(TP0);
	printf("ɾ���ɹ���\n");
}

void SearchbyKey(PtoLT head)	{
	int key,des=0;
	printf("������Ҫ���ҵĹؼ��֣�");
	scanf("%d",&key);
	while (head!=NULL)	{
		if (head->Data!=key)
			++des,head=head->Next;
		else	break;
	}
	if (head!=NULL)
		printf("λ�ã�%d	���ݣ�%d\n",des,key);
	else
		printf("���޴�Ԫ�أ�\n");
}

void Print(PtoLT head)	{
	if (!head)	{
		printf("����Ϊ�գ�\n");
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
	printf("�������ȣ�%d\n",len);
}

void destroyLinkTable(PtoLT &head)	{
	while (head!=NULL)	{
		PtoLT T0=head;
		head=head->Next;
		free(T0);
	}
	printf("���ٳɹ���\n");
}



