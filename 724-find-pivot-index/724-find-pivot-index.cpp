class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_sum(n,0);
        
        for(int i=n-2; i>=0; i--){
            right_sum[i] = right_sum[i+1] + nums[i+1];
        }
        
        int left = 0;
        
        for(int i=0; i<n; i++){
            if(left == right_sum[i]){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};