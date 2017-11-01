/*
 * > File Name: ZScanner.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年11月01日 星期三 09时50分50秒
 */

#include <stdio.h>
int main(void)
{
    int array[500][500];
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&array[i][j]);
    
    int x = 0, y = 0;
    int i = 0;
    while(x != n - 1 || y != n -1 ){
        if(y != n -1)
            printf("%d ", array[x][y++]);
        else
            printf("%d ", array[x++][y]);
            
        while(x < n -1 && y > 0)
            printf("%d ",array[x++][y--]);

        if(x != n - 1)
            printf("%d ", array[x++][y]);
        else
            printf("%d ", array[x][y++]);

        while(x > 0 && y < n - 1)
            printf("%d ",array[x--][y++]);
    }
    printf("%d\n",array[n-1][n-1]);
}
