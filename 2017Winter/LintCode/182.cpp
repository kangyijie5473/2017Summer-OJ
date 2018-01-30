class Solution {
public:
    /*
     * @param A: A positive integer which has N digits, A is a string
     * @param l: Remove k digits
     * @return: A string
     */
    string DeleteDigits(string &A, int l) {
        // wrong idea 不是连续的K位 & 0不好处理
        
        // string result;
        // int length = A.size();
        // for(int i = 0; i < length - l; i++){
        //     if(A[i] < A[i + l])
        //         result.push_back(A[i]);
        //     else{
        //         for(i = i + l; i < length; i++)
        //             result.push_back(A[i]);
        //         break;
        //     }
        // }
        // return result;
        // fail example :90245
        
        int length = A.size() - l;
        while(A.size() > length){
            int i = 0;
            while(A[i] <= A[i+1] && i < A.size() -1 )
                i++;
            A.erase(i,1);
        }
        while(*(A.begin()) == '0'){
            A.erase(A.begin());
        }
        return A;
    }
};