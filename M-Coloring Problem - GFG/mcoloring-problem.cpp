// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101], int color[], int v, int currNode, int currColor){

    for(int node=0; node<v; node++){

        if(node != currNode && graph[node][currNode] == 1 && color[node] == currColor)
            return false;
    }
    
    return true;
}

bool helper(bool graph[101][101], int color[], int m, int v, int currNode){ // currNode = 0, v=5
    
    if(currNode == v)
        return true;
        
    for(int col=1; col<=m; col++){

        if(isSafe(graph, color, v, currNode, col)){
            color[currNode] = col;
            
            if(helper(graph, color, m, v, currNode+1))
                return true;
                
            color[currNode] = 0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    
    if(helper(graph, color, m, V, 0))
        return true;
    
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends