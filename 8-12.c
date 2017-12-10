/*
 * @filename:    8-12.c
 * @author:      Crow
 * @date:        2017年12月10日 22:32:15
 * @description:
 */

#include<stdio.h>
#include<stdlib.h>
int array[100][100];
int num;
int getKey(int r, int c)
{
    if(r == num - 1)
        return array[r][c];

    int resultA = getKey(r+1, c);
    int resultB = getKey(r+1, c+1);
    return array[r][c] +  (resultA > resultB ? resultA : resultB); 
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        for(int i = 0; i < num; i++)
            for(int j = 0; j <= i; j++)
                scanf("%d",&array[i][j]);
        printf("%d\n",getKey(0,0));
    }

}
