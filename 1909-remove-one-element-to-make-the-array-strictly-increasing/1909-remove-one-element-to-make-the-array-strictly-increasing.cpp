class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            bool flag = true;
            for(int j=1; j<n; j++){
                if(j==i)
                    continue;
                if((i != 0 && j-1 == i && nums[j-2] >= nums[j]) || (j-1 != i && nums[j-1] >= nums[j])){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                return flag;
        }
        
        return false;
    }
};