#include <iostream>
using namespace std;
int n, m, k;
int getNum()
{
	for(int i = m; i >=0; i--){
		int sum1, sum2;
		if(i > k){
			sum1 = i*k - k*(k-1)/2;
		}else{
			sum1 = i*(i-1);
		}
		if(n-k > i){
			sum2 = i*(i-1);
		}else{
			sum2 = i*(n-k+1) -  (n-k)*(n-k+1)/2;
		}
		//cout << sum1 + sum2 - i << endl;
		if(sum1 + sum2 - i <= m)
			return i;
	}

}
int main()
{
	cin >> n >> m >> k;
	int array[10000] = {0};
	if(k == 0)
		cout << 0 << endl;
	else
		cout << getNum() << endl;
	return 0;
}