class Solution {
public:
    string getSmallestString(string s) {
        
        for(int i=1;i<s.length();i++){
            int next = s[i]-'0';
            int prev = s[i-1]-'0';

            if((prev%2==0 && next%2==0 && next<prev) || (prev%2!=0 && next%2!=0 && next<prev)){
                swap(s[i],s[i-1]);
                break;
            }
            
        }
        return s;

    }
};