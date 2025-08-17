class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int prev = -1;
        vector<string> res;

        for(int i=0;i<words.size();i++){
            if(prev!=groups[i]){
                res.push_back(words[i]);
                prev=groups[i];
            }
        }
        return res;
    }
};