class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int cb = 0;
        int res = 0;
        for(vector<int> vec:boxTypes){
            int box = vec[0] , unit = vec[1];
            if(cb+box<=truckSize){
                res+=(box*unit);
                cb+=box;
              
            }else{
                int diff = abs(cb-truckSize);
                res+=(unit*diff);
               
                break;
            }
        }     
        return res;
    }
};