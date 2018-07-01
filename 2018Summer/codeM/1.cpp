#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in-1", "r", stdin);
	ios::sync_with_stdio(false);
	int n, m, t;
	scanf("%d%d",&n, &m);
	t = n;
	vector<int> price;
	vector<int> sp;
	multimap<int, int> cut_money;
	while(t--){
		int temp, a;
		scanf("%d%d", &temp, &a);
		price.push_back(temp);
		sp.push_back(a);
	}
	while(m--){
		int t, temp;
		scanf("%d%d", &t, &temp);
		cut_money.insert(pair<int,int>(t,temp));
	}
	double planA = 0, planB = 0;
	int max_cut = 0;
	for(int i = 0; i < n; i++){
		planA += (sp[i] == 1) ? price[i]*0.8 : price[i];
		planB += price[i];
	}
	auto f = cut_money.rend();
	for(auto i = cut_money.rbegin(); i != f; i++){
		if(i->first <= planB && i->second > max_cut)
			max_cut = i->second;
	}
	planB -= max_cut;
	printf("%.2f\n",planA < planB ? planA : planB);
	return 0;
}