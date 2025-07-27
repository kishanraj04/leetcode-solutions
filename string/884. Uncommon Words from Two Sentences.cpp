class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> freq;
        int first = 0;
        int last = 0;

        string combine = s1+' '+s2;
        for(int i=0;i<combine.length();i++){
            if(combine[i]==' ' || i>=combine.length()-1){
                last = i;
                if(i>=combine.length()-1){
                    last = i+1;
                }
                freq[combine.substr(first, (last - first))]++;
                first = last+1;
            }
        }
        vector<string> res;
        for(auto [word,f]:freq){
            if(f==1){
              res.push_back(word);
            }
        }
        return res;
    }
};