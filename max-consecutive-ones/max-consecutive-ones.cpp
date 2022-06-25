class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0, n = nums.size();
        
        for(int num : nums){
            if(num != 1){
                res = max(res, count);
                count = 0;
            }else{
                count++;
            }
        }
        
        if(count){
            res = max(res, count);
        }
        
        return res;
    }
};