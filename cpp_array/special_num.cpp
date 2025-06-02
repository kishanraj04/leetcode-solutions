class Solution {
public:
    int colSum(const vector<vector<int>>& mat, int col) {
        int colsum = 0;
        for (int i = 0; i < mat.size(); i++) {
            colsum += mat[i][col];
        }
        return colsum;
    }

    int rowSum(const vector<int>& row) {
        int rowsum = 0;
        for (int val : row) {
            rowsum += val;
        }
        return rowsum;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int special = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    int ts = rowSum(mat[i]) + colSum(mat, j);
                    if (ts == 2) { 
                        special++;
                    }
                }
            }
        }
        return special;
    }
};
