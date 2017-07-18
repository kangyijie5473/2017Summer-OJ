/*
 * > File Name: day2-A.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月18日 星期二 07时47分51秒
 */

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string mail;
    while(getline(cin, mail)){
        auto head = mail.begin();
        auto end  = mail.end();
        end--;
        if(*head == '@' || *head == '.' || *end == '@' || *end == '.'){
            cout << "NO" << endl;
            continue;
        }
        string::size_type at_pos ;
        if((at_pos= mail.find('@')) == string::npos){
            cout << "NO" << endl;
            continue;
        }
        if(mail.find('@',at_pos+1) != string::npos){
            cout << "NO" << endl;
            continue;
        }
        if(mail.find('.',at_pos) == string::npos ||
           mail.find('.',at_pos) == at_pos+1){
               cout << "NO" << endl;
               continue;
           }
        cout << "YES" << endl;
      }
}
