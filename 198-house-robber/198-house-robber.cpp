class Solution {
public:
    int helper(vector<int>& nums, vector<int>& memo, int n){
        if(n==0)
            return nums[0];
        if(n==1)
            return max(nums[0], nums[1]);
        
        if(memo[n] != -1)
            return memo[n];
        
        memo[n] = max(helper(nums, memo, n-1), helper(nums, memo, n-2)+nums[n]);
        return memo[n];
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> memo(n, -1);
        
        int res = helper(nums, memo, n-1);
        
        return res;
    }
};