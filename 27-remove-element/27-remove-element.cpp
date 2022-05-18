class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastIdx = 0;
        for(int traverse=0; traverse<nums.size(); traverse++){
            if(nums[traverse] != val){
                nums[lastIdx++] = nums[traverse];
            }
        }
        
        return lastIdx;
    }
};