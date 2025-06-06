class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                 int val = (triangle[i][j] + triangle[i + 1][j] <= triangle[i][j] + triangle[i + 1][j + 1]) 
                  ? triangle[i][j] + triangle[i + 1][j] 
                  : triangle[i][j] + triangle[i + 1][j + 1];
                  cout<<val<<" ";
        triangle[i][j] = val;
            }
        }
        return triangle[0][0];
    }
};