#include <iostream>
#include <vector>
using namespace std;
void findSum(int sum, vector<int> &a)
{
	auto i = a.begin();
	auto j = a.end() - 1;
	while(i < j - 1)
	{
		if(*i + *j < sum)
			i++;
		else if(*i + *j > sum)
			j--;
		else
			break;
	}
	cout << *i << " " << *j << endl;
	return ;
}
int main(int argc, char const *argv[])
{
	vector<int> a = {1,2,3,4,5,6,7};
	findSum(15, a);
}
