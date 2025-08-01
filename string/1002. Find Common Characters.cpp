class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> m;

        for(string s:words){
            for(char c:s){
                m[c]++;
            }
        }
        
        // traverse on map
        vector<string> res;
        for(auto [key,val] : m){
            int freq = val;
            if(freq>=words.size()){
                while(freq>1){
                    cout<<key<<" "<<freq<<endl;
                    res.push_back(string(1,key));
                    freq/=words.size();
                }
            }
        }
        return res;

       
    }
};