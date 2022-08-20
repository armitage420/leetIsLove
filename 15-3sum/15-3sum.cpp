class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), start, end;
        long long sum;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            int prev1 = -1000001, prev2 = -1000001; 
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            if(nums[i] > 0){
                break;
            }
            
            start = i+1;
            end = n-1;
            
            while(start < end){
                sum = nums[i] + nums[start] + nums[end];
                
                if(sum == 0 && !(nums[start] == prev1 && nums[end] == prev2)){
                    
                    res.push_back({nums[i], nums[start], nums[end]});
                    prev1 = nums[start];
                    prev2 = nums[end];
                    start++;
                    end--;
                }else if(sum < 0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        
        return res;
    }
};