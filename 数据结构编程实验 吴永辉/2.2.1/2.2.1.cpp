#include <iostream>
#include <stdio.h>
#define N 10001
using namespace std;
int main()
{
	int i,next,origin,j;
	bool self[N]={false};
	for (i=1;i<N;i++)
	{
		next=i;origin=i;
		while (next<N)
		{
			while (i>0)
			{
				next+=i%10;
				i/=10;
			}
			i=next;
			if (!self[next]&&next<N) 			//如果可生成，就变1
				self[next]=true;
			else
				break;
		}
		i=origin;
	}
	for (i=1;i<N;i++) 
		if (!self[i])
			cout << i << endl;
	return 0;
} 
