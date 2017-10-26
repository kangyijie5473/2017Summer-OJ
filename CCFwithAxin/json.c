/*
 * > File Name: json.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月26日 星期四 17时37分37秒
 */

#include <stdio.h>
#include <string.h>
char *queryObj(char queryString[], char buffer[])
{
    char *p,*q;
    char outBuffer[80];
    p = strstr(buffer, queryString);
    if(!p){
        return NULL;
    }else{
        p += (1 + strlen(queryString));
        while(*p != '\0'){
            if(*p == '\"'){
                q = strchr(p+1, '\"');
                memcpy(outBuffer, p, q-p);
                outBuffer[q-p] = '\0';
                return NULL;
            }
            if(*p == '{'){
                return p ;
            }
            p++;
        }
    }
}
int queryObjFinal(char queryString[], char buffer[])
{
    char *p,*q;
    char outBuffer[80];
    p = strstr(buffer, queryString);
    if(!p){
        //printf("NOTEXIST:final not find\n");
        printf("NOTEXIST\n");
        return 1;
    }else{
        p += (1 + strlen(queryString));
        while(*p != '\0'){
            if(*p == '\"'){
                p++;
                q = strchr(p+1, '\"');
                memcpy(outBuffer, p, q-p);
                outBuffer[q-p] = '\0';
                printf("STRING %s\n",outBuffer);
                return 0;
            }
            if(*p == '{'){
                printf("OBJECT\n");
                return 0 ;
            }
            p++;
        }
    }
}
void queryJson(char queryString[],char buffer[])
{
    char *debug;
    char *queryStringEnd = &queryString[0];
    if(!strchr(queryString, '.')){
        if(debug = strchr((char *)buffer+1, '{'))
        {
            if(strstr(buffer, queryString) > debug){
                //printf("NOTEXIST:More OBJECT\n");
                printf("NOTEXIST\n");
                return;
            }
        }
        queryObjFinal(queryString, buffer);
        return;
    }
        
    while(*queryStringEnd != '.' && *queryStringEnd != '\0')
        queryStringEnd++;
    *queryStringEnd = '\0';
    char *queryStringHead = queryStringEnd + 1;
    char *bufferHead = queryObj(queryString, buffer);
    if(!bufferHead){
        //printf("NOTEXIST:mid not find\n");
        printf("NOTEXIST\n");
        return;
    }else
        queryJson(queryStringHead, bufferHead);
}
int main(void)
{
    int n,m,offset = 0;
    scanf("%d%d",&n,&m);
    //n = 10;
    //m = 5; 
    char buffer[8000] ;
    char *head = &buffer[0];
    
    
    while(n--){
        fgets(head, 80, stdin);
        offset = strlen(head);
        head += offset;
    }
    
    while(m--){
        char queryString[90];
        scanf("%s",(char *)queryString + 1);
        queryString[0] = '\"';
        int len = strlen(queryString);
        queryString[len] = '\"';
        queryString[len+1] = '\0';
        queryJson(queryString,buffer);
    }
}
