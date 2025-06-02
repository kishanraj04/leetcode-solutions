class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> strength;

        for (int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 1)
                    count++;
                else
                    break; 
            }
            strength.push_back({count, i});
        }

      
        sort(strength.begin(), strength.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(strength[i].second);
        }

        return result;
    }
};
