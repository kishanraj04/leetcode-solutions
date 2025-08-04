class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : text) {
            freq[ch]++;
        }

        int m = INT_MAX;
        string word = "balloon";
        for (char ch : word) {
            if (freq[ch]) {

                if (ch == 'l') m = min(m, freq[ch]/2);
                else if (ch == 'o') m = min(m, freq[ch]/2);
                else m = min(m, freq[ch]);
            } else {
                return 0;
            }
        }

        return m;
    }
};
