class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> combination, int currSum, int currIdx){
        
        if(currSum > target)
            return;
        
        if(currSum == target){
            result.push_back(combination);
            return;
        }
        
        for(int i=currIdx; i<candidates.size(); i++){
            
            int num = candidates[i];
            currSum += num;
            combination.push_back(num);
            helper(candidates, target, result, combination, currSum, i);
            currSum -= num;
            combination.pop_back();
  
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        helper(candidates, target, result, {}, 0, 0);
        return result;
        
    }
};