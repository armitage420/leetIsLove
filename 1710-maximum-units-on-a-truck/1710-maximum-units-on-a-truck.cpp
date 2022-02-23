class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int>> q;
        for(auto nums : boxTypes){
            int numOfBoxes = nums[0];
            int noOfUnits = nums[1];
            
            q.push({noOfUnits, numOfBoxes});
        }
        
        int countUnits = 0;
        while(truckSize > 0 && !q.empty()){
            int numOfBoxes = q.top().second;
            int noOfUnits = q.top().first;
            
            q.pop();
            
            // printf("num of boxes: %d, no of units: %d, truck size: %d, count units: %d.\n", numOfBoxes, noOfUnits, truckSize, countUnits);
            
            if(numOfBoxes <= truckSize){
                
                truckSize -= numOfBoxes;
                countUnits += (numOfBoxes * noOfUnits);
                // printf("boxes <= truckSize, num of boxes: %d, no of units: %d, truck size: %d, count units: %d.\n", numOfBoxes, noOfUnits, truckSize, countUnits);
            }else if(truckSize > 0){
                
                cout << (numOfBoxes - truckSize);
                countUnits += truckSize*noOfUnits;
                truckSize = 0;
                // printf("boxes > truckSize, num of boxes: %d, no of units: %d, truck size: %d, count units: %d.\n", numOfBoxes, noOfUnits, truckSize, countUnits);
            }
        }
        
        return countUnits;
    }
};