class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        if(A.size() <= 1)
            return 0;
        int step = A[0];
        int c = 1;
        int length = A.size();
        for(int i = 0 ; i < length-1; i++){
            if(step >= length -1)
                break;
            step = step >= i+A[i]? step : (c++,i+A[i]);
            
        }
        return c;
        
    }
};