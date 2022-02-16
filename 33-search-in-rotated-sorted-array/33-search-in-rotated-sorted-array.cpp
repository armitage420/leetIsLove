class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = 0, res = -1;
        
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1])
                pivot = i;
        }
        
        if(target > nums[n-1])
            res = binarySearch(nums, 0, pivot-1, target);
        else
            res = binarySearch(nums, pivot, n-1, target);
        
        return res;
    }
    
    int binarySearch(vector<int>& nums, int start, int end, int& target){
    
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        return -1;
    }
};