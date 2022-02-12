class Solution {
public:
    
    int findingTheCandidate(vector<int>& nums){
        
        int majorityIdx = 0, count = 1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[majorityIdx]){
                count++;
            }else{
                count--;
            }
            
            if(!count){
                majorityIdx = i;
                count = 1;
            }
        }
        
        return nums[majorityIdx];
    }
    
//     int isMajority(vector<int>& nums, int candidate){
        
//         int count = 0, n = nums.size();
        
//         for(int i=0; i<n; i++){
//             if(nums[i] == candidate){
//                 count++;
//             }
//         }
        
//         return (count > (n/2));
//     }
    
    int majorityElement(vector<int>& nums) {
        return findingTheCandidate(nums);
    }
};