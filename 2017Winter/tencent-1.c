/*
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗
 */
#include <stdio.h>
#include <string.h>
void swap(char *str, int index, int end)
{
	char temp = str[index];
	for(int i = index; i < end -1; i++)
		str[i] = str[i+1];
	str[end-1] = temp;
}
int main()
{
    char str[1010];
    while(scanf("%s", str) != EOF){

	    int length = strlen(str);
	    int i = length - 1;
	    while(str[i] >= 'A' && str[i] <= 'Z' && i >= 0)
	    	i--;
	    int end = i+1;
	    for(; i >= 0; i--){
	    	if(str[i] >= 'A' && str[i] <= 'Z' ){
	    		swap(str, i, end);
	    		end--;
	    	}
	    }
	    //printf("%p\n", str);
	    printf("%s\n", str);
	}
    return 0;
    
}