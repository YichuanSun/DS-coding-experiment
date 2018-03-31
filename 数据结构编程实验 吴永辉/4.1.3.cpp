#include <stdio.h>
#include <string.h>
#define N 1010
freopen("a.txt",'r',stdin);
char a[N],b[N];
int A[N],B[N];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	while (n--)
	{
		int p=0;
		scanf("%s%s",a,b);
		for (i=0;a[i]!='\0';i++)
		{
			A[p]=a[i]-'0';
			if (b[i]!='\0')
				B[p++]=b[i]-'0';
		}
		for (i=0;i<N;i++)
		{
			A[i]+=B[i];
			if (A[i]>9)
			{
				A[i]-=10;
				A[i+1]++;
			}
		}
		for (j=0;A[j]==0;j++);
		for (k=N-1;A[k]==0;k--);
		for (i=j;i<=k;i++)
			printf("%d",A[i]);
		printf("\n");
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
	}
	return 0;
}
