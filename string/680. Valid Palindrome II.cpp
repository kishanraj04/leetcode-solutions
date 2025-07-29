class Solution {

bool isPalindrome(int si,int ei,string s){
    while(si<=ei){
        if(s[si]!=s[ei]){
            return false;
        }
        si++;
        ei--;
    }
    return true;
}

public:
    bool validPalindrome(string s) {
        
        int si = 0;
        int ei = s.length()-1;
        int dc = 0;
        while(si<=ei){
            if(s[si]==s[ei]){
                si++;
                ei--;
            }else{
                return isPalindrome(si,ei-1,s) || isPalindrome(si+1,ei,s);
            }
        }
        return true;
    }
};