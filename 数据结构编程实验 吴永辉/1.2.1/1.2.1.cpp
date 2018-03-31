#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100
int main()
{
//	freopen("aaa.txt","r",stdin);
	int i=0,j,k,a[N]={0};
	cin >> a[0];
	while (a[0]!=-1)
	{
		i=0;k=0;
		while (a[i]!=0)
		{
			i++;
			cin >> a[i];
		}
		for (i=0;a[i]!=0;i++)
		{
			for (j=i+1;a[j]!=0;j++)
			{
				if (a[i]*2==a[j]||a[j]*2==a[i])
					k++;
			}
		}
		cout << k << endl;
		cin >> a[0];
	}
	return 0;
}
