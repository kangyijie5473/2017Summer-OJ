class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        int length = nums.size();
        if(nums[0] < nums[length-1])
            return nums[0];
        if(nums[length-2] > nums[length-1])
            return nums[length-1];
        int start = 0;
        int end = length-1;
        int mid;
        while(nums[start]>nums[end]){
            if(end - start ==1)
                return nums[end];
            mid = (end+start)/2 ;
            if(nums[mid] > nums[start])
                start = mid;
            else
                end = mid;
            
        }
        return nums[mid];
    }
};