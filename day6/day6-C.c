/*
 * > File Name: day6-C.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月22日 星期六 15时56分21秒
 */

#include <stdio.h>
int main(void)
{
    int c,v0,v1,a,l;
    scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
    int day = 2;
    int read_new =v0 ;
    int read_sum = v0;
    if(c <= v0){
        printf("1\n");
        return 1;
    }
    for(; read_sum < c; day++){
        if(v0 + a*(day-1) < v1)
            read_new = v0 + a*(day-1) - l;
        else read_new = v1 - l;
        read_sum += read_new;
    }
    printf("%d\n",day-1);

}
