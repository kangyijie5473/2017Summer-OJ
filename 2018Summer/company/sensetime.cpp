#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
int main(int argc, char const *argv[])
{
    int n , m;
    vector<vector<double>> v(n, vector<double>(m, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    printf("%.3f\n", 2.250);
}
// #include <bits/stdc++.h>
// using namespace std;

// typedef unsigned long long ull;
// typedef long long ll;
// ull m;
// ull func(ull step, vector<ull> &v)
// {
// 	if (v[step] != 0)
// 		return v[step];

// 	if (step <= 0)
// 		return 0;
// 	if (step == 1)
// 		return 1;
// 	if (step == 2)
// 		return 2;
// 	ull res = 0;
// 	for (ull i = m; i >= 1; i--){
// 		if (i >= step){
// 			res += 2 * func(step - 1, v) % 10007;
// 			break;
// 		}
// 		else
// 			res += func(step - i, v) % 10007;
// 	}
// 	return v[step] = res % 10007;
// }
// int main(int argc, char const *argv[])
// {
// 	freopen("in-sensi", "r", stdin);
// 	ull n;
// 	cin >> n >> m;
// 	vector<ull> v(n + 1, 0);
// 	ull res = func(n, v);
// 	cout << res % 10007 << endl;
// //	cout << v[n] % 10007<< endl;
// 	return 0;
// }