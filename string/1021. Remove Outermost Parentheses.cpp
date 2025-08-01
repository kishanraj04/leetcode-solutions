class Solution {
public:
    string removeOuterParentheses(string s) {

        string res = "";
        int open = 0;
        for(char ch:s){
            if(ch=='('){
                if(open>0) res+="(";
                open++;
            }
            else{
                open--;
                if(open>0) res+=")";
            }
        }        
        return res;
    }
};