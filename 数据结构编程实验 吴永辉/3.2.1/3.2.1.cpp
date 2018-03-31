#include <iostream>
using namespace std;
void print(int n)
{
	string s;
	cin >> s;
	cout << s << endl;
	if (--n) {
		cin >> s;
		if (--n) print(n);
		cout << s << endl;
	} 
}
int main(void)
{
	int n,loop = 0;
	cin >> n;
	while (n) {
		cout << "SET" << ++loop <<endl;
		print(n);
		cin >> n;
	}
	return 0;
}
