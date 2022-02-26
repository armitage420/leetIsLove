class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        
        // first time is for getting the number with most growth, hence nominator and denominator is not increased here
        // growth --> possible growth
        for(int i=0; i<n; i++){
            
            int nom=classes[i][0], den=classes[i][1];
            double growth = (double)(nom+1)/(den+1) - (double)(nom)/(den);
            pq.push({growth,{nom, den}});
        }
        
        while(extraStudents--){
            
            auto val = pq.top();
            pq.pop();
            int nom=val.second.first + 1;
            int den=val.second.second + 1;
            
            double growth=(double)(nom+1)/(den+1) - (double)(nom)/(den);
            pq.push({growth,{nom,den}});
        }
        
        double res = 0;
        while(!pq.empty()){
            
            auto val = pq.top();
            pq.pop();
            
            res+=(double) val.second.first/val.second.second;
        }
        
        return (double) res/n;
    }
};