class Solution {
public:
    bool isSafe(vector<vector<int>>& adjList, vector<int>& color, int n, int currGarden, int currColor){
        for(int i=0; i<adjList[currGarden].size(); i++){
            if(color[adjList[currGarden][i]-1] == currColor){
                return false;
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<int>>& adjList, vector<int>& color, int n, int currGarden){
        
        if(currGarden == (n+1)){
            return true;
        }
        
        for(int col = 1; col <= n; col++){
            if(color[currGarden-1] == 0 && isSafe(adjList, color, n, currGarden, col)){
                color[currGarden-1] = col;
                if(helper(adjList, color, n, currGarden+1))
                    return true;
                color[currGarden-1] = 0;
            }
        }
        
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjList(n+1);
        vector<int> color(n, 0);
        
        
        for(auto edge : paths){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        helper(adjList, color, n, 1);
        
        return color;
    }
};