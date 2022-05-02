class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        
        for(auto pair:m){
            if(s.find(pair.second) == s.end()){
                s.insert(pair.second);
            }else{
                return false;
            }
        }
        
        return true;
    }
};