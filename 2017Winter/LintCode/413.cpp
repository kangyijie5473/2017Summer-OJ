class Solution {
public:
    /*
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    
    // give up or continue?
    // I don't know
     
    int reverseInteger(int n) {
        
        // my plan...
        
        // long long result = 0;
        // int flag = 0;
        // if(n < 0){
        //     n *= -1;
        //     flag = 1;
        // }
        // char buffer[100];
        // int i = 0;
        // while(n){
        //     buffer[i++] = n%10;
        //     n /= 10;
        // }
        // long long num = 1;
        // for(int j = i - 1; j>=0; j--){
        //     result += buffer[j] * num;
        //     if((result >= 2147483647 && !flag) || (result >=2147483648 && flag))
        //         return 0;
        //     num *= 10;
        // }
        // if(flag)
        //     result *= -1;
        // return num=result;
        
        //plan 2: very clearly
        
        // long long res = 0;  
        // while (n != 0) {  
        //     res = 10 * res + n % 10;  
        //     n /= 10;  
        // }  
        // return ( res < INT_MIN || res > INT_MAX ) ? 0 : res;
    }
};