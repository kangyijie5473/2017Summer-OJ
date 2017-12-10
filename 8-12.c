/*
 * @filename:    8-12.c
 * @author:      Crow
 * @date:        2017年12月10日 22:32:15
 * @description:
 */

#include<stdio.h>
#include<string.h>

int array[100][100];
int result[100][100];

int num;
int getKey(int r, int c)
{
    if(r == num - 1)
        return array[r][c];
    
    int resultA,resultB;
    if(result[r+1][c])
        resultA = result[r+1][c];
    else 
        resultA = getKey(r+1, c);
    if(result[r+1][c+1])
        resultB = result[r+1][c+1];
    else
        resultB = getKey(r+1, c+1);
    return result[r][c] = array[r][c] +  (resultA > resultB ? resultA : resultB); 
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
        memset(result, 0, 100 * 100 * sizeof(int));
    }

}
