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
		while (low+1<high)		// ����֮ǰ��(low<=high),������Ӳ�׵Ķ��ַ��������ϸ���Ŀ���龳 
		{
			mid=(low+high)/2;
			if (cl-len[mid]>delta)		 
				low=mid;		// ����ط�Ҳ��Ӧ�����ϸ���1��low=mid+1; ���� 
			else if (cl-len[mid]<delta)
				high=mid;		// ����ط�Ҳ��Ӧ�����¸���1�� high=mid-1;���� 
			else if (cl-len[mid]==delta) 		//����û����ô�ɵ���� 
			{
				printf("%d card(s)\n",mid);
				goto end;
			}
		}
		printf("%d card(s)\n",high);		//����ط�ԭ�������midҲ���ԣ�Ӧ�÷����龰������Ͻ� 
		scanf("%lf",&cl);
	}
	end:;
	return 0;
}
