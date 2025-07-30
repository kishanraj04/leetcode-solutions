class Solution {
public:
    string reverseOnlyLetters(string s) {
        int sp = 0, lp = s.length() - 1;

        while (sp < lp) {
            if (!isalpha(s[sp])) {
                sp++;
            } else if (!isalpha(s[lp])) {
                lp--;
            } else {
                swap(s[sp], s[lp]);
                sp++;
                lp--;
            }
        }

        return s;
    }
};
