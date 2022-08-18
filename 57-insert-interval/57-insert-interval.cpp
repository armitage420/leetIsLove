class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        bool inserted = false;
        
        if(n==0){
           return {newInterval}; 
        }
            
        for(int i=0; i<n; i++){
            
            if((intervals[i][0] <= newInterval[1]) && (intervals[i][1] >= newInterval[0])){
                
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                
            }else{
                if(!inserted && (intervals[i][0] > newInterval[1])){
                    res.push_back(newInterval);
                    inserted = true;
                }
                
                res.push_back(intervals[i]);
            }
        }
        
        if(!inserted){
            res.push_back(newInterval);
            
        }
        return res;
    }
};