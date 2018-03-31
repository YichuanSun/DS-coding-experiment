#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
#define pi 3.14159

int main()
{
	int i=1,n;
	float dis,x,y,area;
	scanf("%d",&n);
	while (i<=n)
	{
		scanf("%f %f",&x,&y);
		dis=(x*x+y*y);
		area=pi*dis/2;
		printf("property %d : This property will begin eroding in year %d\n",i,(int)ceil(area/50));
		i++;
	}
	printf("END OF OUTPUT\n");
	return 0;
}
