class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  
            map[sortedWord].push_back(word);
        }

        vector<vector<string>> res;
        for (auto& entry : map) {
            res.push_back(entry.second);
        }

        return res;
    }
};
