#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#define N 10000
using namespace std;

int main()
{
	int i,j,k=0,prime[N]={0},n,sum=0,s;
	for (i=2;i<=10000;i++)		//最傻的枚举法，SB一样 
	{
		for (j=2;j<i;j++)
			if (i%j==0)
				break;
		if (j==i)
			prime[k++]=i;
	}
/*	for (i=2;i<=10000;i++)  		//这是之前用的高效算法，但是莫名其妙的错了 
	{
		s=(int)ceil(sqrt(i));
		for (j=2;j<s;j++)
		{
			s=(int)ceil(sqrt(i));
			if (i%j==0)
				break;
		}
		if (j==(int)ceil(sqrt(i)))
			prime[k++]=i;
	}
*/
	cin >> n;
	k=0;
	while (n)
	{
		for (i=0;n>=prime[i];i++)
		{
			for (j=i;sum<n;j++)
			{
				sum=sum+prime[j];
			}
			if (sum==n)
				k++;
			sum=0;
		}
		cout << k << endl;
		k=0;
		cin >> n;
	}
	//for (i=0;prime[i]!=0;i++)
	//	cout << prime[i] << endl;
	//cout << "Time:" << (double)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
