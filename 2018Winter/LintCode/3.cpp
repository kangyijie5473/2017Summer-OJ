#include <iostream>
using namespace std;
bool judge(int i, int k)
{
    while(i) {
        if (i % 10 == k)
            return true;
        else
            i /= 10;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n, k, c = 0;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        if (judge(i, k))
            c++;
    cout << c << endl;
    return 0;
}
