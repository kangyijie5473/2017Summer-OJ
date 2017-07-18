/*
 * > File Name: day2-B.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月18日 星期二 08时16分03秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int max = 0, min = 100;
    int sum = 0, n, score,num;
    float ave_score;
    while(cin >> n){
        num = n;
        while(n--){
            cin >> score;
            if(score <= min)
                min = score;
            if(score >= max)
                max = score;
            sum += score;
            cout << sum << endl;
        }
        sum -= min;
        sum -= max;
        ave_score = sum/(float)(num-2);
        printf("%.2f\n",ave_score);
        min = 100;
        sum = max = 0;
    }
}
