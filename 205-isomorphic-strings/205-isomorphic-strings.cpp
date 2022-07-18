class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hmap;
        
        for(int i=0; i<s.length(); i++){
            if(hmap.count(s[i]) && hmap[s[i]] != t[i]){
                return false;
            }else{
                hmap[s[i]] = t[i];
            }
        }
        
        hmap.clear();
        
        for(int i=0; i<s.length(); i++){
            if(hmap.count(t[i]) && hmap[t[i]] != s[i]){
                return false;
            }else{
                hmap[t[i]] = s[i];
            }
        }
        
        return true;
    }
};