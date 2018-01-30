class Solution {
public:
    /*
     * @param n: a number
     * @return: Gray code
     */

     vector<int> grayCode(int n) {
         vector<deque<char>> code;
         vector<int> result;
         result.push_back(0);
         if(n == 0){
             return result;
         }
         result.push_back(1);
    
         if(n == 1){
             return result;
         }
         result.clear();
         deque<char> d1(1,'0');
         deque<char> d2(1,'1');
         code.push_back(d1);
         code.push_back(d2);
    
         for(int i = 1; i < n; i++){
             int length = code.size();
             for(int i = length - 1; i >= 0; i--){
                 code.push_back(code[i]);
             }
             for(int i = 0; i < length; i++){
                 code[i].push_front('0');
             }
             for(int i = length; i < length * 2; i++){
                 code[i].push_front('1');
             }
             
         }
         for(auto i : code){
             int temp = 0;
             int power = 1;
             for(auto j = i.rbegin(); j != i.rend(); j++){
                 temp += (*j - '0')* power;
                 power *= 2;
             }
             result.push_back(temp);
         }
         return result;
     }

};