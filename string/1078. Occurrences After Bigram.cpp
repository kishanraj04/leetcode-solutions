class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        stringstream ss(text);
        string word;

        // Split the text into words
        while (ss >> word) {
            words.push_back(word);
        }

        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            if (i+2<words.size() && words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }

        return result;
    }
};
