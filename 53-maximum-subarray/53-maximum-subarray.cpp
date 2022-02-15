class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN; // also handles the single largest values
        int curr_max = 0; // handles the breaking of sums after contiguous ones
        
        for(auto num : nums){
            curr_max = num + curr_max;
            if(num > curr_max)
                curr_max = num;
            
            if(curr_max > max_so_far)
                max_so_far = curr_max;
        }
        
        return max_so_far;
    }
};