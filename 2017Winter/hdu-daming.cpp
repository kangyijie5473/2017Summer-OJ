/*
 * @filename:    hdu-daming.cpp
 * @author:      Crow
 * @date:        2017年12月20日 09:24:39
 * @description:
 */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
    freopen("in-daming","r",stdin);
    string a,b;
    string::size_type a_dot_index,b_dot_index,a_num,b_num;
    while(cin >> a >> b){
        a_dot_index = a.find(".");
        b_dot_index = b.find(".");
        a_num = a.size() - a_dot_index - 1;
        b_num = b.size() - b_dot_index - 1;
        if(a_num > b_num){
            for(unsigned long  i = 1; i <= a_num - b_num; ++i)
                b.push_back('0');
        }else if(a_num < b_num){
            for(unsigned long  i = 1; i <= b_num - a_num; i++)
                a.push_back('0');
        }  
        string::size_type i  = a.size() - 1; 
        string::size_type j  = b.size() - 1; 
        bool flag = false;
        char result;
        string final_result;
        for(; i != a_dot_index; i--,j--){

            if(flag)
                result = a[i] + b[j] - '0' - '0' + 1;
            else
                result = a[i] + b[j] - '0' - '0';

            if(result > 9){
                flag = true;
                result = result - 10 + '0';
            }else{
                flag = false;
                result += '0';
            }

            final_result.push_back(result);
        }
        final_result.push_back('.');
        i--,j--;
        while(1){
            if(flag)
                result = a[i] + b[j] - '0' - '0' + 1;
            else
                result = a[i] + b[j] - '0' - '0';

            if(result > 9){
                flag = true;
                result = result - 10 + '0';
            }else{
                flag = false;
                result += '0';
            }

            final_result.push_back(result);

            if(i == 0 || j == 0)
                break;
            i--,j--;
        }
        if(j){
            do{
                j--;
                if(flag)
                    result = b[j] - '0' + 1;
                else
                    result = b[j] - '0';

                if(result > 9){
                    flag = true;
                    result = result - 10 + '0';
                }else{
                    flag = false;
                    result += '0';
                }
                final_result.push_back(result);
            }while(j != 0);
        }else if(i){
                do{
                    j--;
                    if(flag)
                        result = b[j] - '0' + 1;
                    else
                        result = b[j] - '0';

                    if(result > 9){
                        flag = true;
                        result = result - 10 + '0';
                    }else{
                        flag = false;
                        result += '0';
                    }
                    final_result.push_back(result);
                }while(j != 0);
            }else if(flag){
            final_result.push_back('1');
            }
        reverse(final_result.begin(), final_result.end());
        cout << final_result << endl;
    }
}
