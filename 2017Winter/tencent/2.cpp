#include <bits/stdc++.h>
using namespace std;
int main()
{
	// freopen("t","r", stdin);
	int n, m;
	cin >> n >> m;
	multimap<int,int> task, machine, r_task, r_machine;
	while(n--){
		int x,y;
		cin >> x >> y;
		machine.insert({y,x});
		r_machine.insert({x,y});
	}
	while(m--){
		int z,w;
		cin >> z >> w;
		task.insert({w,z});
		r_task.insert({z,w});
	}
	auto j = machine.begin();
	typedef unsigned long long ull;
	ull sum = 0;
	ull c = 0;
	for(auto i = task.begin(); i != task.end(); i++,j++){
		if(j == machine.end())
			break;
		if(i->first <= j->first && i->second <= j->second){
			sum += 200*(i->second) + 3*(i->first);
			c++;
		}

	}
	j = r_machine.begin();
	ull r_sum = 0, r_c = 0;
	for(auto i = r_task.begin(); i != r_task.end(); i++,j++){
		if(j == r_machine.end())
			break;
		if(i->second <= j->second && i->first <= j->first){
			r_sum += 200*(i->first) + 3*(i->second);
			r_c++;
		}

	}
	// cout << "test" << c << " " << sum << "||" << r_c << r_sum <<endl;	
	if(c > r_c)
		cout << c << " "<< sum;
	else
		cout << r_c << " " << r_sum;
	return 0;
}