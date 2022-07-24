class Solution {
public:
    void floodFillDfs(vector<vector<int>>& image, int sr, int sc, int defaultColor, int color, int r, int c){
        if(sr < 0 || sr >= r || sc < 0 || sc >= c || image[sr][sc] != defaultColor)
            return;
        
        image[sr][sc] = color;
        floodFillDfs(image, sr+1, sc, defaultColor, color, r, c);
        floodFillDfs(image, sr-1, sc, defaultColor, color, r, c);
        floodFillDfs(image, sr, sc+1, defaultColor, color, r, c);
        floodFillDfs(image, sr, sc-1, defaultColor, color, r, c);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            floodFillDfs(image, sr, sc, image[sr][sc], color, image.size(), image[0].size());
        return image;
    }
};