#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const double maxlen=5.2;
vector<double> cardlen;
void createlen()    {
    double len=0.5;
    cardlen.push_back(0);
    for (int i=1;cardlen[i-1]<=maxlen;)   {
        cardlen.push_back(len+cardlen[i-1]);
        len=1.0/(++i+1);
        //cout<<"len:"<<len<<endl;
    }
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    double n;
    createlen();
    //cout<<cardlen.size()<<endl;
    int Size=cardlen.size();
    //for (int i=0;i<=cardlen.size();i++)
    //    cout<<i<<'\t'<<cardlen[i]<<endl;
    cin>>n;
    while (n)   {
        int i;
        for (i=0;i<=Size;i++)
            if (cardlen[i]*1000>=n*1000)   {
                cout<<i<<' '<<"card(s)"<<endl;
                break;
            }
        cin>>n;
    }
    return 0;
}
