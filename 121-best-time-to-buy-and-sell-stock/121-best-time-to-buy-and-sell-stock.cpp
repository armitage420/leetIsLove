class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1)
            return 0;
        
        int minPrice = prices[0], maxProfitShare = 0;
        for(int i=1; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            
            int profitToday = prices[i] - minPrice;
            
            maxProfitShare = max(maxProfitShare, profitToday);
        }
        
        return maxProfitShare;
    }
};