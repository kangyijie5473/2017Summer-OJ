/*
 * @filename:    hdu-HowManyTable.cpp
 * @author:      Jack Kang
 * @date:        2017年11月19日 21:24:43
 * @description:
 */

#include <iostream>
using namespace std;
int pre[1001];
int result[1001];
int flag[1001];
int find_(int& e)
{
    int t = e;
    while(pre[t] != t)
        t = pre[t];
    return t;
}
void union_(int e, int v)
{
    int e_root = find_(e);
    int v_root = find_(v);
    if(e_root != v_root)
        pre[v_root] = e_root;
}
int main(void)
{
    int d,e,v;
    cin >> d; 
    while(d--){
        int cnt = 0;
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            pre[i] = i, result[i] = 0;
        while(m--){
            cin >> e >> v;
            union_(e, v);
        }
  for(int i = 0; i <= n; i++)
        result[find_(i)]++;
        for(int i = 0; i <= n; i++)
            if(result[i])
                cnt++;
        cout << cnt << endl;
        
    }
}
