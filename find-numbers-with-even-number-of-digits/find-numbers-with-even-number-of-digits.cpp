class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int num : nums){
            if(num){
                int digits = log10(num) + 1;
                if((digits & 1) == 0){
                    res++;
                }
            }
        }
        
        return res;
    }
};