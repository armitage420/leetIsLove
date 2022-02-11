class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++){
            hmap[nums[i]] = i;
        }
        
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            int key = target - nums[i];
            
            if(hmap.count(key) && hmap[key] != i){
                return {i, hmap[key]};
            }
        }
        
        return {};
    }
};