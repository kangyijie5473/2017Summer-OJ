class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int result = A[0];
        int length = A.size();
        for(int i = 1; i < length; i++){
            result = result ^ A[i];
        }
        return result;
    }
};