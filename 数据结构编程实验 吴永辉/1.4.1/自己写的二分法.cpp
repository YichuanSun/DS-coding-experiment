#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
#define delta 1e-8
int main()
{
	int i,low,high,mid;
	double len[N]={0.0},cl;
	for (i=0;i<N;i++)
		len[i+1]=len[i]+1.0/(i+2);
	scanf("%lf",&cl);
	while(cl-delta>0)
	{
		low=0;high=N-1;
		while (low+1<high)		// 改正之前是(low<=high),是生搬硬套的二分法，不符合该题目的情境 
		{
			mid=(low+high)/2;
			if (cl-len[mid]>delta)		 
				low=mid;		// 这个地方也不应该向上浮动1，low=mid+1; 不对 
			else if (cl-len[mid]<delta)
				high=mid;		// 这个地方也不应该向下浮动1， high=mid-1;不对 
			else if (cl-len[mid]==delta) 		//几乎没有这么巧的情况 
			{
				printf("%d card(s)\n",mid);
				goto end;
			}
		}
		printf("%d card(s)\n",high);		//这个地方原先输出的mid也不对，应该符合情景地输出上界 
		scanf("%lf",&cl);
	}
	end:;
	return 0;
}
