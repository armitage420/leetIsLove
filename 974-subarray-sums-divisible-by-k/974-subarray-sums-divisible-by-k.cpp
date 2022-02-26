class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size(), count=0, rem, prefixsum = 0;
        unordered_map<int, int> hmap;
        hmap[0] = 1;
        
        for(int i=0; i<n; i++){
            
            prefixsum += nums[i];
            rem = prefixsum%k;
            if(rem < 0)
                rem += k;
            if(hmap.count(rem)){
                count += hmap[rem];
            }
            
            hmap[rem]++;
        }
        
        return count;
    }
};