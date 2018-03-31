#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
#define pi 3.141592
int n;				//改了全局变量之后，一切稀奇古怪的问题都解决了。 
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
		while (dis[i]>=r[j])		//dis大于r，说明点还在半圆外
		{
			j++;
		}
		printf("Property %d :This property will begin eroding in year %d\n",i,j);
	}
	printf("END OF OUTPUT\n");
}

