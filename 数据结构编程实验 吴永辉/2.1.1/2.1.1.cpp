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
//在学这些东西之前，我肯定会构造好几个数组，把数据塞进去，然后再存储，再计算，再输出。 
//那样程序肯定会有更多的时间复杂度和空间复杂度。这个简洁的多。这样看来，我这几天是进步了的。 
