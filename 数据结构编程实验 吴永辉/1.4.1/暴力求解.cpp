#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define delta 0.000001
int main()
{
	int i=1;
	double cl=0,t;
	scanf("%lf",&t);
	while (t)
	{
		cl+=1.0/(i+1);
		while (t-cl>delta)
		{
			i++;
			cl+=1.0/(i+1);
		}
		printf("%d card(s)\n",i);
		scanf("%lf",&t);
		i=1;cl=0;
	}
	return 0;
}
