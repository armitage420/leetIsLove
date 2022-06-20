class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        
        unordered_map<char, int> hmap;
        
        hmap['I'] = 1;
        hmap['V'] = 5;
        hmap['X'] = 10;
        hmap['L'] = 50;
        hmap['C'] = 100;
        hmap['D'] = 500;
        hmap['M'] = 1000;
        
        int res = hmap[s[n-1]];
        int curr_int, prev_int = res;
        
        for(int i=n-2; i>=0; i--){
            
            curr_int = hmap[s[i]];
            
            if(curr_int < prev_int){
                res -= curr_int;
            }else{
                res += curr_int;
            }
            
            prev_int = curr_int;
        }
        
        return res;
    }
};