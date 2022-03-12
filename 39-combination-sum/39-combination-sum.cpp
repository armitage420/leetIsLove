class Solution {
public:
    int n;
    
    void helper(vector<int>& candidates, int idx, int target, vector<vector<int>>& res, vector<int>& comb){
        
        if(target == 0){
            res.push_back(comb);
            return;
        }
            
        if(idx >= n)
            return;
        
        if(candidates[idx] <= target){
            comb.push_back(candidates[idx]);
            helper(candidates, idx, target-candidates[idx], res, comb);
            comb.pop_back();
        }
        helper(candidates, idx+1, target, res, comb);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> res;
        vector<int> comb;
        helper(candidates, 0, target, res, comb);
        
        return res;
    }
};