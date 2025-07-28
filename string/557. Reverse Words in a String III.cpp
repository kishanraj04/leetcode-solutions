class Solution {
public:
    string reverseWords(string s) {
        
        int si=0;
        int li=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(s.begin()+si,s.begin()+i);
                si=i+1;
            }
        }
        reverse(s.begin()+si,s.begin()+s.length());
        return s;
    }
};