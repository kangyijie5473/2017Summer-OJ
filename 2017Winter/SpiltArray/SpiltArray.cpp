/*
    @From: http://www.lintcode.com/zh-cn/problem/partition-array-by-odd-and-even/
    @Time Complexity: O(n)
 */

#include <iostream>
using namespace std;
int main(void)
{
	freopen("in-SpiltArray","r", stdin);
	int src[10];
	for(int i = 0; i < 10; i++){
		scanf("%d",&src[i]);
	}

	int *p = &src[0]; // head
	int *q = &src[9]; // tail
	while(p < q){
		while(*p % 2 && p < q)      // find even
			p++;
		while(*q % 2 == 0 && p < q) // find odd 
			q--;
		// swap two numbers 
		if(p < q){
			int temp = *p;
			*p = *q;
			*q = temp;
		}else
			break;
	}

	for(int i = 0; i < 10; i++)
		printf("%d ", src[i]);
}