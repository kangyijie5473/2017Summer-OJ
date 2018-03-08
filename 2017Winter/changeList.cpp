#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }
    if(n == 1){
        cout << t << endl;
        return 0;
    }
    int base_index = n / 2;
    int *result = new int[100000];
    for(int i = 0; i < n; i++){
        int offset = (i+1) / 2;
        if(i%2 == 0){
            if(n % 2 == 0){
                result[base_index + offset] = v[i];
            }else{
                result[base_index - offset] = v[i];
            }
        }else{
            if(n % 2 == 0){
                result[base_index - offset] = v[i];
            }else{
                result[base_index + offset] = v[i];
            }
        }

    }
    for(int i = 0; i < n; i++){
       if(i == n-1)
            cout << result[i] << endl;
        else
            cout << result[i] << ' ';
    }
    return 0;
}