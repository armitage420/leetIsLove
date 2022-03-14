class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx, vector<vector<int>>& res, vector<int>& comb){
        if(target == 0){
            
            res.push_back(comb);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            comb.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, res, comb);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, res, comb);
        return res;
    }
};