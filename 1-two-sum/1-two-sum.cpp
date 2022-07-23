class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> targetIndexMapping;
        
        for(int i=0; i<n; i++){
            if(targetIndexMapping.count(target-nums[i])){
                return {targetIndexMapping[target-nums[i]], i};
            }
            
            targetIndexMapping[nums[i]] = i;
        }
        
        return {};
    }
};