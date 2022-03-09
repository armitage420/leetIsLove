class Solution {
public:
    static bool comp(string &x, string &y){
        
        int a = x.find(' ');
        int b = y.find(' ');
        
        string x1 = x.substr(a+1);
        string y1 = y.substr(b+1);
        // if a and b are equal then let<number> is the deciding factor
        if(x1==y1)
            return x < y;
        return x1 < y1;
        
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> res;
        vector<string> letters;
        vector<string> digits;
        
        for(auto log : logs){
            
            int space = log.find(' ');
            if(log[space+1] >= '0' && log[space+1] <= '9'){
                digits.push_back(log);
            }else{
                letters.push_back(log);
            }
        }
        
        sort(letters.begin(), letters.end(), comp);
        res.insert(res.end(), letters.begin(), letters.end());
        res.insert(res.end(), digits.begin(), digits.end());
        
        return res;
    }
};