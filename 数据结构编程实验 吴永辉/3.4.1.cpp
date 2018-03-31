#include <iostream>
#include <string>
#include <cstring>
#define N 21

using namespace std;
void search(int i,int j);
bool judge[N][N];
int ans=0,m,n;
string map[N];

int main()
{
	int i,j;
	cin >> m >> n;
	while (m||n)
	{
		for (i=0;i<n;i++)
			cin >> map[i];
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				if (map[i][j]=='@')
					goto spot;
		spot:; 
		memset(judge,false,sizeof(judge));
		search(i,j);
		cout << ans-1 <<endl;
		ans=0;
		cin >> m >> n;
	}
	return 0;
}

void search(int i,int j)
{
	if (judge[i][j]||i<0||i>=n||map[i][j]=='#'||j<0||j>=m)
		return;
	judge[i][j]=true;
	ans++;
	search(i-1,j);
	search(i+1,j);
	search(i,j-1);
	search(i,j+1);
}
