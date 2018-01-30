class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
     
     // 你就是这样，一句话就击败我所有的防备。
     // 然后就丢下我。
     
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int *p = (int *)malloc(4 * (m + n));
        int *q = p;
        while(i < m && j < n){
            if(A[i] < B[j]){
                *q = A[i++];
                
            }else
                *q = B[j++];
            q++;
        }
        while(i < m){
            *q = A[i++];
            q++;
        }
        while(j < n){
            *q = B[j++];
            q++;
        }
        memcpy(A, p, 4 * (m+n));
        free(p);
    }
};