class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int> cf;

        for(char ch:chars){
            cf[ch]++;
        }

      
       int c = 0;
        for(string s:words){
            unordered_map<char,int> tf;
            for(char ch:s){
                tf[ch]++;
            }

            // map of tf entries
            bool flag = true;
            for(auto [key,val]:tf){
                if(cf.find(key)==cf.end() || val>cf[key]){
                    flag = false;
                    break;
                }
            }
            if(flag) c+=s.length();
        }
        return c;
    }
};