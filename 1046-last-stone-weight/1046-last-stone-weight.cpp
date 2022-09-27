class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==1)
            return stones[0];
        
        priority_queue<int> pq;
        for(int wt : stones){
            pq.push(wt);
        }
        
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x != y){
                pq.push(abs(x-y));
            }
        }
        
        if(!pq.empty())
            return pq.top();
        
        return 0;
    }
};