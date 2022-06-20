class Solution {
public:
    string commonPrefix(string& s1, string& s2){
        int n1 = s1.length(), n2 = s2.length();
        
        n1 = min(n1, n2);
        string prefix = "";
        for(int i = 0; i < n1; i++){
            if(s1[i] != s2[i]){
                break;
            }
            
            prefix += s1[i];
        }
        
        return prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = strs[0];
        
        for(int i=1; i<n; i++){
            if(res == "")
                break;
            
            res = commonPrefix(res, strs[i]);
        }
        
        return res;
    }
};