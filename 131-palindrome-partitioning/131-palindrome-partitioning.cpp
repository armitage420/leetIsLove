class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
              
                return false;
            }
            
            l++;
            r--;
        }
        
        
        return true;
    }
    
    void helper(vector<vector<string>>& res, vector<string> partition, string& s, int n, int idx){
        if(idx >= n){
            res.push_back(partition);
            return;
        }
        
        string sub;
        for(int i=idx; i<n; i++){
            sub = s.substr(idx, i-idx+1);
           
            if(isPalindrome(s, idx, i)){
                
                partition.push_back(sub);
                helper(res, partition, s, n, i+1);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        
        vector<string> partition;
        
        helper(res, partition, s, s.length(), 0);
        
        return res;
    }
};