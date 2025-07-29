class Solution {

string check(string str){
    string ts = "";
    for(int i=0;i<str.length();i++){
        if(str[i]!='#'){
            ts+=str[i];
        }else{
            while(str[i]=='#' && ts.length()>=1){
                ts.pop_back();
                i++;
            }
            ts+=str[i];
        }
    }
    return ts;
}

public:
    bool backspaceCompare(string s, string t) {
        string ss = "";
        string ts = "";

        // traverse on s
        return check(s) == check(t);
    }
};