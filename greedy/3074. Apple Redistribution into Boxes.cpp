class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        sort(capacity.begin(),capacity.end(),greater<int>());

        // sum of apple
        int as = 0;
        for(int a:apple){
            as+=a;
        }

        int cap=0;
        int m = 0;
        for(int c:capacity){
            if(cap>=as){
                break;
            }
            else{
                cap+=c;
                m++;
            }
        }
        return m;
    }
};