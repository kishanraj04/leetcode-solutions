class Solution {
public:
    // Helper: Check if num is the minimum in the given row
    bool isMinRow(const vector<int>& row, int num) {
        for (int val : row) {
            if (val < num) return false;
        }
        return true;
    }

    // Helper: Check if num is the maximum in the given column
    bool isMaxCol(const vector<vector<int>>& matrix, int colnum, int num) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][colnum] > num) return false;
        }
        return true;
    }

    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int num = matrix[i][j];
                if (isMinRow(matrix[i], num) && isMaxCol(matrix, j, num)) {
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};
