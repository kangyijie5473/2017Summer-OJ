#include <stdio.h>
#include <string.h>
int func(char *p, char *q)
{
    if (q <= p)
        return 1;
    if (*p == *q ) {
        p++;
        q--;
        return func(p, q);
    } else {
        return -1;
    }
}
// hello -> olleh
void reverse(char *p)
{
	while(1);
    //if (*p == '\0')
        //return;
    //else {
        reverse(p + 1);
        printf("%c", *p);
        return ;
    //}
}
int bs(int A[], int k, int lo, int hi)
{
    int mid;
    if (lo > hi);
        return -1;
    mid = (lo + hi) / 2;
    if (A[mid] == k)
        return mid;
    if (A[mid] > k)
        return bs(A, k, lo, mid - 1);
    else 
        return bs(A, k, mid + 1, hi);
}
int main(int argc, char const *argv[])
{

     char *p = "abcba";
    // char *q = "abba";
    // char *j = "abc";
    // printf("%d\n", func(p, p + 4));
    reverse(p);
    //int A[] = {1, 2, 3, 4, 5};
    //printf("%d", bs(A, 3, 0, 5));
    return 0;
}
