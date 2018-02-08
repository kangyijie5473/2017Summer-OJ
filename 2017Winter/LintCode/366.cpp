class Solution {
public:
    /*
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int table[100];
    int fibonacci(int n) {
        if(table[n])
            return table[n];
        if(n == 1)
            return table[n] = 0;
        if(n == 2)
            return table[n] = 1;
        return table[n] = fibonacci(n-1) + fibonacci(n-2);
            
    }
};