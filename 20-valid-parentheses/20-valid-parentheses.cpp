class Solution {
public:
    bool checkOpenParenthesis(char ch){
        if(ch == '(' || ch == '{' || ch == '[')
            return true;
        
        return false;
    }
    
    bool isParenthesisMatch(stack<char>& st, char ch){
        if(st.empty())
            return false;
        
        char ch2 = st.top();
        if((ch2 == '(' && ch == ')') || (ch2 == '{' && ch == '}') || (ch2 == '[' && ch == ']')){
            st.pop();
            return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        int n = s.length();
        if(n==1)
            return false;
        
        stack<char> openParenthesis;
        for(int i=0; i<n; i++){
            if(checkOpenParenthesis(s[i])){
                openParenthesis.push(s[i]);
            }else{
                if(!isParenthesisMatch(openParenthesis, s[i])){
                    return false;
                }
            }
        }
        
        return openParenthesis.empty();
    }
};