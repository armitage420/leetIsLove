class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        int start = 0, end = 0;
        for(int i=1; i<intervals.size(); i++){
            
            if(intervals[end][1] >= intervals[i][0] && intervals[end][1] <= intervals[i][1]){
                end = i;
            }else if(intervals[end][1] < intervals[i][0]){
                res.push_back({intervals[start][0], max(intervals[end][1], intervals[start][1])});
                start = i;
                end = i;
            }
        }
        
        res.push_back({intervals[start][0], intervals[end][1]});
        return res;
    }
};