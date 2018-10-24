#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
	int graph[10][10] = {0};
	int now_x, now_y;
	int point;
	int power;
	scanf("(%d,%d),%d,%d", &now_x, &now_y, &point, &power);
	for (int i = 0; i < 10; i++) {
		 for (int j = 0; j < 10; j++) {
		 	char c = getchar();
		 	graph[i][j] = c;
		 	getchar();
		 }
	}
	for (int i = 0; i < 10; i++) {
		 for (int j = 0; j < 10; j++) {
		 	cout << graph[i][j] << ' ';
		 }
		 cout << endl;
	}
	return 0;
}

/*
int main(int argc, char const *argv[])
{
	int n;
	multimap<int, string> res;
	cin >> n;
	while (n--) {
		string temp;
		cin >> temp;
		int key = 0;
		int power = 1;
		if (temp[temp.size() - 1] == 'T') {
			power = 1000000;
		}else if (temp[temp.size() - 1] == 'G') {
			power = 1000;
		}else {
			power = 1;
		}
		string value = temp;
		temp.pop_back();
		key = atoi(temp.c_str());
		res.insert(make_pair(key * power, value));
	}
	for (auto i = res.begin(); i != res.end(); i++)
		cout << i->second << endl;
	return 0;
}
*/
/*
int main()
{
    string str;
    cin >> str;
    int count[26] = {0};
    for (auto i = str.begin(); i != str.end(); i++){
        count[*i-'a']++;

    }
    int c = 0;
    int index = 0;
    set<int> res;
    for (int i = 25; i >= 0; i--) {
        if (c < count[i]) {
        	res.clear();
            index = i;
            c = count[i];
            res.insert(index);
        }else if (c == count[i]) 
        	res.insert(index);
    }
    if (res.size() > 1)
	    for (auto i : str) {
	    	if (res.find(i - 'a') != res.end())
	    		printf("%c\n%d", i, c);
	    }
    printf("%c\n%d", index + 'a', c);
}
*/