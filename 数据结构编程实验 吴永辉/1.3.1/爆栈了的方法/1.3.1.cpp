#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
#define pi 3.141592
int n;				//����ȫ�ֱ���֮��һ��ϡ��Źֵ����ⶼ����ˡ� 
int main()
{
	int i,j;
	double x[N]={0},y[N]={0},dis[N]={0},r[N]={0},area=0;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%lf %lf",&x[i],&y[i]);
		dis[i]=sqrt(x[i]*x[i]+y[i]*y[i]);
	}
	for (i=0;i<N;i++)
	{
		area+=50;
		r[i+1]=sqrt(area*2/pi); 
	}
	
	for (i=0;i<n;i++)
	{
		j=0;
		while (dis[i]>=r[j])		//dis����r��˵���㻹�ڰ�Բ��
		{
			j++;
		}
		printf("Property %d :This property will begin eroding in year %d\n",i,j);
	}
	printf("END OF OUTPUT\n");
}

