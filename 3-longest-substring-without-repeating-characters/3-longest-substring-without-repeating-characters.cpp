class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.length();
        
        if(strLen == 0)
            return 0;
        
        int largestFoundSize = 0;
        int currentPtrStart = 0, currentPtrEnd;
        
        
        unordered_map<char, int> hmap;
        hmap[s[0]] = 0;
        
        for(currentPtrEnd = 1; currentPtrEnd < strLen; currentPtrEnd++){
            
            if(hmap.count(s[currentPtrEnd]) && hmap[s[currentPtrEnd]] >= currentPtrStart){
                
                largestFoundSize = max(currentPtrEnd-currentPtrStart, largestFoundSize);
                currentPtrStart = hmap[s[currentPtrEnd]] + 1;
            }
            
            hmap[s[currentPtrEnd]] = currentPtrEnd;
        }
        
        largestFoundSize = max(currentPtrEnd-currentPtrStart, largestFoundSize);
        return largestFoundSize;
    }
};

/*
Rough algo (if I want to return string):
1. largestfoundptrStart = largerstfoundptrEnd = 0, currentptrStart = currentptrEnd = 0
2. hashmap to record the last idx of distinct character
3. increase the currentPtrEnd and keep saving the respective values unless a repeating character is found
4. if a repeating charater is found
    a. update the largestfoundptrs start & end if the difference between currentptrs start and end-1 is greater
    b. change the currentptr start to map[recentRepeatingCharacter] + 1 (currentPtrEnd is the index of recent repeating character)
    c. end the loop when currentptr reaches the end of string 
5. check outside the loop if the difference between currentptrs start and end-1 is greater, and update required values
6. return the substring recorded
*/