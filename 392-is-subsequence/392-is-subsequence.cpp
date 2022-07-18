class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length(), n2 = t.length(), k = 0;
        
        for(int i=0; i<n2; i++){
            if(s[k] == t[i]){
                k++;
            }
            
            if(k==n1){
                return true;
            }
        }
        
        return (k==n1);
    }
};