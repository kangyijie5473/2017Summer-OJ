class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    struct SumIndex{
         SumIndex(int s, int i):sum(s),index(i){}
         int sum;
         int index;
    };
    vector<int> subarraySumClosest(vector<int> &nums) {
        vector<SumIndex> v;
        vector<int> result;

        int length = nums.size();
        if(length == 1){
            result.push_back(0);
            result.push_back(0);

            return result;
        }
        int sum = 0;
        SumIndex temp(0, 0);
        v.push_back(temp);
        for(int i = 0; i < length; i++){
            sum += nums[i];
            SumIndex temp(sum, i+1);
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), [](const SumIndex& a, const SumIndex& b){return a.sum < b.sum;});
        int rA = 0, rB = 1, Min = 10000;
        for(int i = 0; i < length-1; i++){
            if(abs(v[i].sum - v[i+1].sum) < Min){
                rA = min(v[i].index,v[i+1].index);
                rB = max(v[i].index,v[i+1].index)-1;
                Min = abs(v[i].sum - v[i+1].sum);
            }
        }
        result.push_back(rA);
        result.push_back(rB);
        return result;
    }

};