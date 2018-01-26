class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        int result = 0;
        int bits[32] = {0};
        int length = A.size();
        for(int i =0; i < length; i++){
            for(int j = 0; j < 32; j++){
                bits[j] += A[i] & 0x01;
                A[i] >>= 1;
            }
        }
        int num = 1;
        for(int j = 0; j < 32; j++){
            bits[j] %= 3;
            result += bits[j] * num;
            num *= 2;
        }

        return result;
    }
};