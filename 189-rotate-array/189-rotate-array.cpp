class Solution {
public:
    void swap(int& x, int& y){
        int z = x;
        x = y;
        y = z;
    }
    void rotate_helper(vector<int>& nums, int start, int end, int n){
//         if(start<0 || end<0 || start>=n || end>=n )
//             return;
        
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int partition = n-k;
        
        rotate_helper(nums, 0, partition-1, n);
        rotate_helper(nums, partition, n-1, n);
    
        rotate_helper(nums, 0, n-1, n);
    }
};