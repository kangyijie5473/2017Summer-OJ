#include <bits/stdc++.h>
using namespace  std;
#define mn 1000  
int main()  
{   
    int i,m,n,r,t;  
    int p[mn],q[mn];  
  
    for (i = 0; i < mn; i++) {  
        p[i] = -1;  
        q[i] = 0;  
    }  
  
    cin >> m >> n;  
    t = 0; 
    r = m; 
  
    while (r != 0 && p[r] ==-1) {  
        p[r] = t;             
        r = 10 * r;            
  
        t++;  
        q[t] = r / n;             
        r = r % n;              
    }
    if (r != 0) { 
        cout << p[r] << ' '<< t - p[r] << endl;
    }  
}  