/*
 * > File Name: day6-B.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月22日 星期六 08时32分59秒
 */

#include <stdio.h>
int main(void)
{
    int a,b,sum,res[1000];
    int n,i = 0;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        a %= 100;
        b %= 100;
        sum = a+b;
        sum %= 100;
        res[i++] = sum;
    }
    for(int j = 0; j < i; j++)
        printf("%d\n",res[j]);

}
