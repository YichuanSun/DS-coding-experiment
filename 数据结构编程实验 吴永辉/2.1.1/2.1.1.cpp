#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,kilo,n,speed,hour,hourp;
	while (scanf("%d",&n),n>0)
	{
		i=kilo=hour=hourp=speed=0;
		while (i<n)
		{
			hourp=hour;
			scanf("%d %d",&speed,&hour);
			kilo=kilo+speed*(hour-hourp);
			i++;
		}
		printf("%d miles\n",kilo);
	}
	return 0;
}
//��ѧ��Щ����֮ǰ���ҿ϶��ṹ��ü������飬����������ȥ��Ȼ���ٴ洢���ټ��㣬������� 
//��������϶����и����ʱ�临�ӶȺͿռ临�Ӷȡ�������Ķࡣ�������������⼸���ǽ����˵ġ� 
