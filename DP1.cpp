/*
 * @filename:    DP1.c
 * @author:      KangKang
 * @date:        2017年12月11日 13:39:42
 * @description:
 */

#include<stdio.h>
#include<string.h>
int graph[1001][1001];
int d[1001];
int num;
struct node{
    int x,y;
};
struct node nodes[1001];
int dp(int i)
{
    int &ans  = d[i];
    if(ans > 0)
        return ans;
    ans = 1;
    for(int j = 0; j < 1001; j++)
        if(graph[i][j]){
            int dpRes = dp(j) + 1;
            ans = ans > dpRes ? ans : dpRes;
        }
    return ans;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        for(int i = 0; i < num; i++){
            scanf("%d%d",&nodes[i].x,&nodes[i].y);
        }
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if((nodes[i].x > nodes[j].x && nodes[i].y > nodes[j].y) || (nodes[i].y > nodes[j].x && nodes[i].x > nodes[j].y))
                    graph[i][j] = 1;
            }
        }

        int temp,result = -1;
        for(int i = 0; i < num; i++){
            temp = dp(i);
            if(temp > result)
                result = temp;
        }
        printf("%d\n",result); 
        memset(graph, 0, 1001 * 1001 * sizeof(int));
        memset(d, 0, 1001 * sizeof(int));
        memset(nodes, 0, sizeof(struct node) * 1001);
    }

}
