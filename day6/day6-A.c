/*
 * > File Name: day6-A.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月22日 星期六 08时10分54秒
 */

#include <stdio.h>
#include <string.h>
int main(void)
{
    int n;
    char number[100];
    int len;
    scanf("%d",&n);
    while(n--){
        scanf("%s",number);
        len = strlen(number);
        number[len - 6] = '6';
        printf("%s\n",&number[len - 6]);
    }
}
