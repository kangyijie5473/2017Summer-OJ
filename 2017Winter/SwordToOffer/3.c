#include <stdio.h>
int main()
{
	freopen("3-in", "r", stdin);
	int key;
	scanf("%d", &key);
	int n ;
	scanf("%d", &n);
	int array[1000][1000];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &array[i][j]);
		}
	}
	int r = 0;    
	int c = n - 1;
	// (r,c) is start postion
	while(array[r][c] != key){
		if(array[r][c] < key)
			r++;
		else
			c--;
		if(r == n || c < 0){
			printf("No\n");
			return -1;
		}
	}
	printf("yes index = %d %d\n",r,c);
	return 0;
}