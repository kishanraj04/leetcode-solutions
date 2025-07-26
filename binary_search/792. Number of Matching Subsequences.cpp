class Solution {
    string os = "";
    bool isSub(string ss) {

        int p1 = 0;
        for (int i = 0; i < os.length(); i++) {
            if (ss[p1] == os[i]) {
                p1++;
            }
        }
        if (p1 >= ss.length()) {
            return true;
        } else {
            return false;
        }
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // store in map
        unordered_map<char, vector<int>> m;

        for (int i = 0; i < s.length(); i++) {
            m[s[i]].push_back(i);
        }
        int c=0;
        for (string s : words) {
            int li = -1;
            bool isSub = true;
            for (char c : s) {
                auto it = m.find(c);
                if (it == m.end()) {
                    isSub = false;
                    break;
                } else {
                    // Get the vector of indices for character c
                    const vector<int>& idxList = it->second;

                    // Use upper_bound to find the first index > li
                    auto ub = upper_bound(idxList.begin(), idxList.end(), li);
                   
                    if (ub == idxList.end()) {
                        isSub = false;
                        break;
                    }

                   
                    li = *ub;
                }
            }
            if(isSub) c++;
        }

        return c;
    }
};
