class Solution {
public:
    /**
     * @param lower: Integer : lower bound
     * @param upper: Integer : upper bound
     * @return: a list of every possible Digit Divide Numbers
     */
    vector<int> digitDivideNums(int lower, int upper) {
        vector<int> result;
        // wrong answer:TLE(use set)
        // for(int i = lower; i <= upper; i++){
        //     set<int> nums;
        //     // vector<int> Nums;
        //     long long Nums = 0;
        //     int t = i;
        //     int flag = 1;
        //     int five_flag = 0;
        //     while(t){
        //         if(t % 10 == 0){
        //             flag = 0;
        //             break;
        //         }
        //         nums.insert(t%10);
        //         Nums += t % 10;
                
        //         //Nums.push_back(t%10);
        //         // if(t % 10 == 5 && !five_flag)
                    
        //         // five_flag = 1;
        //         t /= 10;
        //     }
        //     if(!flag)
        //         continue;
        //     // if(nums.find(3) != nums.end() && accumulate(Nums.begin(), Nums.end(), 0) % 3 != 0){
        //     //     continue;
        //     // }
        //     if(nums.find(3) != nums.end() && Nums % 3 != 0)
        //         continue;
        //     for(auto n : nums){
        //         if(n == 0||i % n != 0 ){
        //             flag = 0;
        //             break;
        //         }
        //     }
        //     if(flag)
        //         result.push_back(i);
        // }
         
        // simple answer
        for(int i = lower; i>= 0 && i <= upper; i++){ //i might overflow ,so `i>=0`
            if(judge(i))
                result.push_back(i);
        }
        return result;
    }
    int judge(int i){
        int  t = i;
        while(t){
            if(t%10 == 0 || i%(t%10) != 0)
                return 0;
            t /= 10;
        }
        return 1;
    }
};