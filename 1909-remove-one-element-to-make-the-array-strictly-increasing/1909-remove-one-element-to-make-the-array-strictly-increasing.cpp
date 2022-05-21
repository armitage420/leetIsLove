class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)
            return true;
        
        int count_violation = 0;
        
        for(int i=0; i<n-1 && count_violation < 2; i++){
            if(nums[i] >= nums[i+1]){
                count_violation++;
                
                if(i > 0 && nums[i+1] <= nums[i-1]){
                    nums[i+1] = nums[i];
                }
            }
        }
        
        return count_violation < 2; 
    }
};