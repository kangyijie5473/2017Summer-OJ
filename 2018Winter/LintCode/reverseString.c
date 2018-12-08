#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *reverse(const char *str)
{
    int len = strlen(str);
    char *res = (char *)malloc(len);
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
        res[j] = str[i];
    res[j] = '\0';

    return res;
}
int main(int argc, char const *argv[])
{
    char *str = "hello";
    printf("%s\n", reverseString(str));
    return 0;
}
