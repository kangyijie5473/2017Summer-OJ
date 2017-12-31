class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        int a = 0, b = 0,length = A.size();
        for(auto i : A){
            if(i > 0)
                a++;
            else
                b++;
        }
        if(a > b && A[0] < 0){
            for(int i = 1; i < length; i++)
                if(A[i] > 0){
                    swap(A[0],A[i]);
                    break;
                }
        }
        if(b > a && A[0] > 0){
            for(int i = 1; i < length; i++)
                if(A[i] < 0){
                    swap(A[0],A[i]);
                    break;
                }
        }
        int flag = A[0];
        vector<int>::iterator i = A.begin() + 1;
        vector<int>::iterator j = A.begin() + 2;
        while(i < A.end() && j < A.end()){
            while(*i * flag < 0 )
                i = i + 2;
            while(*j * flag > 0 )
                j = j + 2;
            if(i < A.end() && j < A.end()){
                int temp = *i;
                *i = *j;
                *j = temp;
            }else
                break;
            i = i + 2;
            j = j + 2; 
        }

    }
};