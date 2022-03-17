class Solution {
public:
    template <typename T>
    void swap(T& x, T& y){
        T z = x;
        x = y;
        y = z;
    }
    
    void helper(vector<int>& nums, int n, vector<vector<int>>& res, int idx){

        if(idx >= n){

            res.push_back(nums);
            return;
        }
        
        for(int i=idx; i<n; i++){
    
            swap(nums[idx], nums[i]);
            helper(nums, n, res, idx+1);
            swap(nums[idx], nums[i]);
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        helper(nums, nums.size(), res, 0);
        
        return res;
    }
};