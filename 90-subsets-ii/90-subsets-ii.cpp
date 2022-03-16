class Solution {
public:
    void helper(vector<int>& nums, int n, vector<vector<int>>& res, vector<int>& subset, int idx){
        res.push_back(subset);
        
        if(subset.size() >= n){
            return;
        }
        
        
        for(int i=idx; i<n; i++){
            if(i > idx && nums[i]==nums[i-1]) 
                continue;
            subset.push_back(nums[i]);
            helper(nums, n, res, subset, i+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        
        helper(nums, nums.size(), res, subset, 0);
        
        return res;
    }
};