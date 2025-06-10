class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> myMap;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            myMap[nums[i]]++;
        }

        for(const auto [key,value]:myMap){
            if(nums.size()/3<value){
                res.push_back(key);
            }
        }

        return res;
    }
};