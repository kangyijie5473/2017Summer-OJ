class Solution {
public:
    /*
     * @param nums: A list of non negative integers
     * @return: A string
     */
    // 心情惆怅时就写写题， 毕竟我不是那么重要
    
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string str_a,str_b;
            if(a == 0 && b == 0)
                return false;
            while(a){
                str_a.push_back(a%10 + '0');
                a /= 10;
            }
            while(b){
                str_b.push_back(b%10 + '0');
                b /= 10;
            }
            auto i = str_a.rbegin();
            auto j = str_b.rbegin();
            while(1){
                if(*i > *j)
                    return true;
                if(*i < *j){
                    return false;
                }
                if(i + 1 == str_a.rend() && j + 1 == str_b.rend())
                    return true;
                if(i + 1 != str_a.rend())
                    i++;
                if(j + 1 != str_b.rend())
                    j++;

            }
            
        });
        
        string result;
        char buffer[1000] = {0};
        for(auto i : nums){
            sprintf(buffer, "%d", i);
            result.append(buffer);
        }

        while(1){
            auto i = result.begin();
            if(*i == '0' && result.size() > 1){
                result.erase(i);
                continue;
            }else
                break;
            
        }
        return result;
    }
};