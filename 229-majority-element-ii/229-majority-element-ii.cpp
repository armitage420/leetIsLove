class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int x(-1), y(-1), cx(0), cy(0);
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(x == nums[i]){
                cx++;
            }else if(y == nums[i]){
                cy++;
            }else if(!cx){
                cout << nums[i] << " here\n";
                x = nums[i];
                cx = 1;
            }else if(!cy){
                y = nums[i];
                cy = 1;
            }else{
                cx--;
                cy--;
            }
        }
        cout << x << " " << y << endl;
        vector<int> res;
        cx = 0, cy = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == x){
                cx++;
            }
            
            if(nums[i] == y){
                cy++;
            }
        }
        
        if(cx > n/3){
            res.push_back(x);
        }
        
        if(x != y && cy > n/3){
            res.push_back(y);
        }
        
        return res;
    }
};