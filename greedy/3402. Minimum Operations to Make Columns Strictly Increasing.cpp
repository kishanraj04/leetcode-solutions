class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ope = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows; row++) {
                if(row+1<rows){
                    if(grid[row+1][col]<=grid[row][col]){
                        int tp = grid[row][col]-grid[row+1][col];
                        ope+=(tp+1);
                        grid[row+1][col] = grid[row][col]+1;
                    }
                }
            }
           
        }
        return ope;
    }
};