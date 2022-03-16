class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& permute, int arr[], int n){
        if(permute.size() >= n){
            res.push_back(permute);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(!arr[i]){
                arr[i] = 1;
                
                permute.push_back(nums[i]);
                helper(nums, res, permute, arr, n);
                permute.pop_back();
                
                arr[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> res;
        vector<int> permute;
        int arr[n];
        memset(arr, 0, sizeof(arr));
        
        helper(nums, res, permute, arr, n);
        return res;
    }
};