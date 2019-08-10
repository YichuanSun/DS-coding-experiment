#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N];
void post(int le,int ri,int n);
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&a[i]);
    post(0,n-1,n);
    return 0;
}

void post(int le,int ri,int n)  {
    if (n==1)   {printf("%d%c",a[le],le==n-1?'\n':' ');return;}
    post(le+1,(le+ri)/2,n/2);
    post((le+ri)/2+1,ri,n/2);
    printf("%d%c",a[le],le==n-1?'\n':' ');
}
