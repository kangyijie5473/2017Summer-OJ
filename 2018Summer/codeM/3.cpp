#include <bits/stdc++.h>
using namespace std;
int main()
{
	// freopen("in-3", "r", stdin);
	ios::sync_with_stdio(false);
	double g1[16][16] = {0};
	double g2[16] = {0};
	double g3[16] = {0};
	double g4[16] = {0};
	double g5[16] = {0};
	// double result[16] = {0};
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			scanf("%lf", &g1[i][j]);

	// for(int i = 0; i < 16; i++){
	// 	scanf("%lf", &result[i]);
	// }
	int i, j;
	for(int i = 0; i < 16; i++){
		if(i % 2 == 0)
			j = i + 1;
		else
			j = i - 1;
		g2[i] = g1[i][j];
	}

	vector<int> a1 = {0, 1}, a2 = {2, 3}, a3 = {4, 5}, a4 = {6, 7}, a5 = {8, 9}, a6 = {10, 11}, a7 = {12, 13}, a8 = {14, 15};
	for(auto i : a1){
		double temp = 0;
		for(auto j : a2)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];

	}
	for(auto i : a2){
		double temp = 0;
		for(auto j : a1)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}
	for(auto i : a3){
		double temp = 0;
		for(auto j : a4)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}
	for(auto i : a4){
		double temp = 0;
		for(auto j : a3)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}
	for(auto i : a5){
		double temp = 0;
		for(auto j : a6)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}
	for(auto i : a6){
		double temp = 0;
		for(auto j : a5)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}
	for(auto i : a7){
		double temp = 0;
		for(auto j : a8)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}
	for(auto i : a8){
		double temp = 0;
		for(auto j : a7)
			temp += g2[j]*g1[i][j];
		g3[i] = temp*g2[i];
	}

	vector<int> v1 = {0, 1, 2, 3}, v2 = {4, 5, 6, 7}, v3 = {8, 9, 10, 11}, v4 = {12, 13, 14, 15};
	for(auto i : v1){
		double temp = 0;
		for(auto j : v2)
			temp += g3[j]*g1[i][j];
		g4[i] = temp*g3[i];
	}
	for(auto i : v2){
		double temp = 0;
		for(auto j : v1)
			temp += g3[j]*g1[i][j];
		g4[i] = temp*g3[i];
	}
	for(auto i : v3){
		double temp = 0;
		for(auto j : v4)
			temp += g3[j]*g1[i][j];
		g4[i] = temp*g3[i];
	}
	for(auto i : v4){
		double temp = 0;
		for(auto j : v3)
			temp += g3[j]*g1[i][j];
		g4[i] = temp*g3[i];
	}

	vector<int> vv1 = {0, 1, 2, 3, 4, 5, 6, 7}, vv2 = {8, 9, 10, 11, 12, 13, 14, 15};
	for(auto i : vv1){
		double temp = 0;
		for(auto j : vv2)
			temp += g4[j]*g1[i][j];
		g5[i] = temp*g4[i];
	}
	for(auto i : vv2){
		double temp = 0;
		for(auto j : vv1)
			temp += g4[j]*g1[i][j];
		g5[i] = temp*g4[i];
	}


	for(int i = 0; i < 16; i++)
		printf("%.10f ", g5[i]);
	return 0;
}