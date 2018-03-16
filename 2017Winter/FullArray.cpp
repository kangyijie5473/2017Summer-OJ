#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void dfs_(char *str, int start, int end)
{
	if(start == end){
		printf("str is %s\n", str);
		return ;
	}else{
		for(int i = start; i <= end; i++){
			swap(&str[start], &str[i]);
			dfs_(str, start+1, end);
			swap(&str[start], &str[i]);
		}

	}
}
void per(const char *str)
{
	if(!str)
		return ;

	char *p = (char *)malloc(strlen(str));
	memcpy(p, str, strlen(str)+1);
	dfs_(p, 0, strlen(str)-1);
	free(p);
	return;
}

int main()
{
	char str[100] = "123";
	per(str);
	return 0;
}