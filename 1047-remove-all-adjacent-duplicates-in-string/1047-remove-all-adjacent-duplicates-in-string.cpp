class Solution {
public:
    string removeDuplicates(string s) {
        int end, traverse;
        for(end=0, traverse=0; traverse < s.length(); end++, traverse++){
            s[end] = s[traverse];
            if(end > 0 && s[end-1] == s[end]){
                end -= 2;
            }
        }
        
        return s.substr(0, end);
    }
};