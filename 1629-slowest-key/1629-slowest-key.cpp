class Solution {
public:
    char slowestKey(vector<int>& releaseTime, string keysPressed) {
        
        char res = keysPressed[0];
        int lastmax = releaseTime[0];
        
        for(int i=1; i<releaseTime.size(); i++){
            
            int diff = releaseTime[i] - releaseTime[i-1];
            
            if(diff > lastmax || (diff == lastmax && res < keysPressed[i])){
                
                res = keysPressed[i];
                lastmax = diff;
            }
        }
        
        return res;
    }
};