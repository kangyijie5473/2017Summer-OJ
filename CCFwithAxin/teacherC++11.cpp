/*
 * > File Name: teacher.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月24日 星期二 22时08分49秒
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int GETKEY = 0;
const int PUTKEY = 1;
struct Event{
    Event(int eventFlag, int objTime, int objKeyId):flag(eventFlag),time(objTime), keyId(objKeyId){} 
    int flag;
    int time;
    int keyId;
};
bool compareEvent(const Event &e1, const Event &e2){
    if(e1.time < e2.time)
        return true;
    if(e1.time == e2.time){
        if(e1.flag > e2.flag)
            return true;
        if(e1.flag < e2.flag)
            return false;
        if(e1.keyId < e2.keyId)
            return true;
        else
            return false;
     
    }
    return false;
}
int main(void)
{
    //debug
    vector<string> eventType;
    eventType.push_back(string("get"));
    eventType.push_back(string("put"));
    //todo: aync
    vector<Event> taskLine;
    vector<int> keys;
    int numKey;
    int n ;
    scanf("%d%d",&numKey, &n);
    for(int i = 0; i <= numKey; i++)
        keys.push_back(i);
    int keyId,getTime,speedTime;
    while(n--){
        scanf("%d%d%d",&keyId, &getTime, &speedTime);
        taskLine.push_back(std::move(Event(GETKEY, getTime, keyId)));
        taskLine.push_back(std::move(Event(PUTKEY, getTime+speedTime, keyId)));
    }
    sort(taskLine.begin(), taskLine.end(), compareEvent);
    //debug

    //for(const auto i : taskLine)
    //    printf("Event time:%d keyId:%d,type:%s\n",i.time, i.keyId, eventType[i.flag].c_str());
    for( auto ev : taskLine){
        if(ev.flag == GETKEY){
            auto it = find_if(keys.begin(), keys.end(), [ev](const int keyId){return keyId == ev.keyId;});
            *it = -1;  
        }
        if(ev.flag == PUTKEY){
            auto it = find_if(keys.begin(), keys.end(), [](const int keyId){return keyId == -1;});
            *it = ev.keyId;
        }
    }
    //for(auto i : keys)
    //    printf("%d",i);
    for(auto i = keys.begin() + 1; i != keys.end(); ++i)
        printf("%d ",*i);

}
