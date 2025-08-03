class Solution {
public:
    string defangIPaddr(string address) {
        string toadd = "[.]";
        string res = "";
        for(char s:address){
            if(s=='.'){
                res+=toadd;
            }else{
                res+=string(1,s);
            }
        }
        return res;
    }
};