class Solution {
public:
    string reverseStr(string s, int k) {
        

        // travers on string
        int sp = 0;
        int lp = k;
        for(int i=0;i<s.length();i+=(2*k)){
            lp = min(i+k,(int)s.length());
            reverse(s.begin()+i,s.begin()+lp);
        }
        return s;
    }
};