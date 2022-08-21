class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> arr(n+1,0);
        
        for(auto shift : shifts){
            int start = shift[0], end = shift[1], forward = shift[2];
            
            if(forward){
                arr[start] += 1;
                arr[end+1] -= 1;
            }else{
                arr[start] -= 1;
                arr[end+1] += 1;
            }
        }
        
        for(int i=1; i<n; i++){
            arr[i] += arr[i-1];
        }
        
        for(int i=0; i<n; i++){
            int shifted_char = ((s[i]-'a') + arr[i]) % 26;
            
            if(shifted_char < 0)
                shifted_char += 26;
            
            s[i] = ('a' + shifted_char);
        }
        
        return s;
    }
};