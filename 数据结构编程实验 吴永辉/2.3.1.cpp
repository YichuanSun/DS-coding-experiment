#include <stdio.h>

int main()
{
	int i,m=0,f=1,n,t;
	while (scanf("%d",&n),n>0)
	{
		for (i=0;i<n;i++)
		{
			t=m;
			m=m+f;
			f=t+1;
		}
		printf("%d %d\n",m,m+f);
		m=0,f=1;
	}
	return 0;
}
