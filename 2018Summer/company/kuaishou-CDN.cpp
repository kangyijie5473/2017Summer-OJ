
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    struct node *left;
    struct node *right;
    int sum;
    int val;
}Node;
int getSum(Node *p)
{
    if (p == NULL)
        return 0;
    p->sum = getSum(p->left) + getSum(p->right);
    return p->val + p->sum;
}
void midPrintTree(Node *p)
{
    if (p == NULL)
        return ;
    midPrintTree(p->left);
    printf("%d ", p->sum);
    midPrintTree(p->right);
}
int main()
{
	
}
// B - 43%
// int main(int argc, char const *argv[])
// {
// 	freopen("in-kuaishou-CDN", "r", stdin);
// 	int n, w, h;
// 	cin >> n;
// 	ull c = 10000;
// 	vector<vector<int>> *p = new vector<vector<int>>(10000, vector<int>(10000, 0));
// 	vector<vector<int>> &dp = *p;
// 	vector<vector<int>> *pp = new vector<vector<int>>(c, vector<int>(c, 0));
// 	vector<vector<int>> &count = *pp;
// 	while(n--) {
// 		cin >> w >> h;
// 		count[w][h]++;
// 	}
// 	int res = 0;
// 	for (int i = 1; i < 10000; i++) {
// 		for (int j = 1; j < 10000; j++) {
// 			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + count[i][j];
// 			if (dp[i][j] > res)
// 				res = dp[i][j];
// 		}
// 	}
// 	cout << res << endl;
// 	return 0;
// }
// 
//A - AC

// int main(int argc, char const *argv[])
// {
// 	freopen("in-kuaishou-CDN", "r", stdin);
// 	ull n;
// 	cin >> n;
// 	vector<ull> red_pack(n, 0);
// 	for (ull i = 0; i < n; i++)
// 		cin >> red_pack[i];
// 	ull pre = 0;
// 	ull tail = n - 1;
// 	ull sum = 0;
// 	ull pre_sum = red_pack[pre];
// 	ull tail_sum = red_pack[tail];
// 	while (pre < tail) {
// 		if (pre_sum == tail_sum) {
// 			sum = pre_sum;
// 			tail--;
// 			tail_sum += red_pack[tail];
// 		} else if (pre_sum > tail_sum) {
// 			tail--;
// 			tail_sum += red_pack[tail];
// 		} else {
// 			pre++;
// 			pre_sum += red_pack[pre];			
// 		}

// 	}
// 	cout << sum << endl;
// 	return 0;
// }
/*
#include <stdio.h>
#include <string.h>
 
#define MAX 101
 
int Max (int a, int b, int c){
    a = (a > b) ? a : b;
    a = (a > c) ? a : c;
    return a;
}
 
int main(void){
    int n;
    int hash[MAX][MAX][MAX];
    int dp[MAX][MAX][MAX];
    int length;
    int width;
    int height;
    int i;
    int j;
    int k;
    int max;
 
    while (scanf ("%d", &n) != EOF){
        memset (hash, 0, sizeof(hash));
        memset (dp, 0, sizeof(dp));
        for (i=0; i<n; ++i){
            scanf ("%d%d%d", &length, &width, &height);
            ++hash[length][width][height];
        }
        max = 0;
        for (i=1; i<MAX; ++i){
            for (j=1; j<MAX; ++j){
                for (k=1; k<MAX; ++k){
                    dp[i][j][k] = Max (dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]) + hash[i][j][k];
                    if (dp[i][j][k] > max)
                        max = dp[i][j][k];
                }
            }
        }
        printf ("%d\n", max);
    }
    return 0;
}
*/