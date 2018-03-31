#include <iostream>
#define N 12
using namespace std;
int main()
{
	int i;
	double sum=0,wage[N],avg;
	for (i=0;i<N;i++)
	{
		std::cin >> wage[i];
		sum=sum+wage[i];
	}
	avg=sum/N;
	std::cout << "$" << avg << std::endl;
	return 0;
} 
