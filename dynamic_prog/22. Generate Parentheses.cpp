class Solution {
    vector<string> res;
    bool isValid(string str) {
        int c = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(')
                c++;
            else {
                c--;
                if (c < 0)
                    return false;
            };
        }

        if (c == 0)
            return true;
        else
            return false;
    }
    void solve(string& curr, int n, int open, int close) {
        if (curr.length() == n * 2) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');

            solve(curr, n,open+1,close);
             curr.pop_back();
        }
       

        if(close<open){
            curr.push_back(')');
        solve(curr, n,open,close+1);
          curr.pop_back();
        }
      
    }

public:
    vector<string> generateParenthesis(int n) {
        string str = "";

        solve(str, n, 0, 0);
        return res;
    }
};