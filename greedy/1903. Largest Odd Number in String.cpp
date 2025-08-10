class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int li = -1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                li = i;
                break;
            }
        }
        if(li==-1) return "";
        res=num.substr(0,li+1);
        return res;
    }
};