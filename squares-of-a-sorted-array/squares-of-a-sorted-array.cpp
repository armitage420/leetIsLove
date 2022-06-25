class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0, ptr2 = n-1;
        
        vector<int> res(n, 0);
        
        for(int i=n-1; i>=0; i--){
            if(abs(nums[ptr1]) >= abs(nums[ptr2])){
                res[i] = nums[ptr1]*nums[ptr1];
                ptr1++;
            }else{
                res[i] = nums[ptr2]*nums[ptr2];
                ptr2--;
            }
        }
        
        return res;
    }
};