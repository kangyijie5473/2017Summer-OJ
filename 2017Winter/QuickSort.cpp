#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void quickSort(int p, int q, int *nums)
{
	int begin = p;
	int end = q;
	if(begin >= end)
		return ;
	int flag = nums[begin];

	while(begin < end){
		while(nums[end] >= flag && begin < end)
			end--;
		while(nums[begin] <= flag && begin < end)
			begin++;

		if(begin < end)
			swap(&nums[begin], &nums[end]);
	}
	swap(&nums[begin], &nums[p]);
	quickSort(p, begin-1, nums);
	quickSort(begin+1, q, nums);
}

int main()
{
	int nums[] = {9,3,8,4,7,1,9,2};
	quickSort(0, 7, nums);
	for(int i = 0 ; i < 8; i++)
		printf("%d ",nums[i]);
	return 0;
}