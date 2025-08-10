class Solution {
public:
    int minimumMoves(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
            if(s[i]=='X'){
                i+=3-1;
                res++;
            }
        }
        return res;
    }
};