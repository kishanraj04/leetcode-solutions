class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
       map<int,int> mymap;
    for(int i=0; i<nums.size(); i++){
        mymap[nums[i]] = nums[i];
    }

        int count=0;
        int prevkey=INT_MIN;
        int maxim = prevkey;
        bool flag=true;
        for(const auto [key,value]:mymap){
           if(prevkey+1==key){
    count++;
}else{
    if(flag==false) maxim = max(maxim, count);
    count = 0;
    flag = false;
}

            prevkey=key;
        }
        
        return max(count,maxim)+1;
    }
};