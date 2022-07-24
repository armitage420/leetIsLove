class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = -100000;
        int currMax = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            maxSoFar = max(maxSoFar, currMax);
            currMax = max(currMax+nums[i], nums[i]);
        }
        
        return max(maxSoFar, currMax);
    }
};