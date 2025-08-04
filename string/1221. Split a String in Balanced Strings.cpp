class Solution {
public:
    int balancedStringSplit(string s) {
        int b=0;
        int res = 0;
        for(char ch : s){
            if(ch=='L'){
                b++;
            }
            else if(ch=='R'){
                b--;
            }
            if(b==0){
                res++;
            }
        }
        return res;
    }
};