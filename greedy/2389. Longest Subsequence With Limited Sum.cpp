class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        // sort(queries.begin(),queries.end());

        int cs = 0;
        int ci = 0;
        int count = 0;
        vector<int> res;
        for(int v:queries){

            for(int i=0;i<nums.size();i++){
                if(nums[i]+cs<=v){
                    ci++;
                    cs+=nums[i];
                    ++count;
                }
            }
            if(res.size()<queries.size()){
                res.push_back(count);
            }else{
                break;
            }
            count=0;
            cs=0;
        }
        return res;
    }
};