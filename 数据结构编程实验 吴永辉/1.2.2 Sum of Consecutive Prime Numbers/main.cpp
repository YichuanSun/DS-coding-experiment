#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool isPrime(int t);
void createPrime()  {
    for (int i=2;i<=10000;i++){
        if (isPrime(i)) {
            //cout<<i<<"is prime"<<endl;
            v.push_back(i);
        }
        //else cout<<i<<"isn't prime"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    createPrime();
    int a,s=v.size();
    //cout<<"This"<<(int)sqrt(15)<<"\t"<<sqrt(15)<<endl;
    //cout<<"v[25]=    "<<v[25]<<endl;
    //for (int i=0;i<s;i++)   cout<<v[i]<<endl;
    cout<<"This is size "<<s<<endl;
    while (cin>>a)   {
        if (a==0)   break;
        int cnt=0;
        for (int i=0;a>=v[i];i++)    {
            int ans=0;      //����������ans֮ǰ�Ǻ�cntһ���壬�ʹ��ˣ���Ϊ�����Ļ�
            for (int j=i;j<s+1&&ans<a;j++)  {   //ans�ͻ᲻ͣ���ۼӣ�������������Ҫ��ÿһ����ʼ��һ�ۼ�
                ans+=v[j];
            }
            if (ans==a) cnt++;
        }
        cout<<cnt<<endl;
    }
    /*      //���õ��������
    int m;
    cin>>m;
    while (m)   {
        int ans=0;
        for (int i=0;v[i]<=m;i++)    {
            int cnt=0;
            for (int j=i;j<s+1&&cnt<m;j++)
                cnt+=v[j];
            if (cnt==m) ++ans;
        }
        cout<<ans<<endl;
        cin>>m;
    }
    */
    return 0;
}
bool isPrime(int t) {
    if (t==0||t==1)   return false;
    if (t==2) return true;
    for (int i=2;i<=(int)sqrt(t);i++)
        if (t%i==0) return false;
    return true;
}
