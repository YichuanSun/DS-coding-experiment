#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N 100
using namespace std;

int main()
{
	//freopen("a.txt","r",stdin);
	int n,j=1;
	scanf("%d",&n);
	getchar();
	while (n>0)
	{
		int i=0;
		char a[N][N]={'\0'};
		while (i<n)
		{
			gets(a[i]);
			i++;
		}
		i=0;
		cout << "SET " << j <<endl;
		for (i=0;a[i][0]!='\0';i+=2)
			puts(a[i]);
		if (n%2)
			for (i=n-2;i>0;i-=2)
				puts(a[i]);
		else
			for (i=n-1;i>0;i-=2)
				puts(a[i]);
		scanf("%d",&n);getchar();j++;
	}
	return 0;
}

//第33行 ，如果我写成scanf("%d ",&n);j++;确实也能吸收缓冲区，但是我输入0就退出不了了。 我只有输入0+空格才能退出，所以别用。 
