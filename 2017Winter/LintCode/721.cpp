class Solution {
public:
    /*
     * @param : a number
     * @return: return the next sparse number behind x
     */
    int nextSparseNum(int x) {
        // string t;
        // while(x){
        //     t.push_back(x%2 + '0');
        //     x /= 2;
        // }
        // if(t.find("11") != string::npos)
        //     return 0;
        // else
        //     return 1;
        char buffer[32] = {0};
        int length = 1;
        while(x){
            buffer[length++] = x % 2 ;
            x /= 2;
        }

        reverse(&buffer[1], &buffer[length]);


        int j = 1;
        int flag = 1;
        while(flag){
            flag = 0;
            for(j = 1; j < length; j++){
                if(buffer[j] == 1 && buffer[j+1] == 1){
                    buffer[j-1] = 1;
                    for(int k = j; k < length; k++){
                        buffer[k] = 0;
                    }
                    flag = 1;
                    break;
                }
            }

        }


        int power = 1;
        int result = 0;
        for(int k = length - 1; k >= 0; k--){
            result += power * buffer[k];
            power *= 2;
        }
        return result;
    }

};