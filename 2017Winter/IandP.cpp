/*
 * @filename:    IandP.cpp
 * @author:      Crow
 * @date:        2017年12月12日 19:32:47
 * @description:
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int array[1000000];
int main(void)
{
    //freopen("in.txt","r", stdin);
    int n;
    int num;
    int max = 0;
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; ++i){
            scanf("%d",&num);
            array[num]++;
            if(max < num)
                max = num;
        }
        for(int i = 0; i <= max; ++i){
            if(array[i] >= (n+1) / 2){
                printf("%d\n",i);
                break;
            }
        }
        memset(array, 0, 1000000 * sizeof(int));
    }
}
