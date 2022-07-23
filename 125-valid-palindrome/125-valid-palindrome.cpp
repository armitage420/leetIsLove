class Solution {
public:
    bool isAlphanumeric(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return true;
        }
        
        return false;
    }
    
    bool isSameChar(char ch1, char ch2){
        if(tolower(ch1) == tolower(ch2)){
            return true;
        }
        
        return false;
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        if(n==1)
            return true;
        
        int start = 0, end = n-1;
        while(start < end){
            if(!isAlphanumeric(s[start])){
                start++;
            }else if(!isAlphanumeric(s[end])){
                end--;
            }else if(!isSameChar(s[start], s[end])){
                return false;
            }else{
                start++;
                end--;
            }
        }
        
        return true;
    }
};