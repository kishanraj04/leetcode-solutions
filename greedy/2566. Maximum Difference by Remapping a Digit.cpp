class Solution {

public:
    int minMaxDifference(int num) {

        string nums = to_string(num);
        string maxn = "";
        string minn = "";

       

        // find first non 9 and first non 0;
        char st=' ';
        char nd=' ';
        bool flag1 = true;
        bool flag2 = true;
        int si = 0;
        while (si<nums.size()){
            if(flag1 && nums[si]!='9'){
                flag1=false;
                st=nums[si];
            }
            if(flag2 && nums[si]!='0'){
                flag2=false;
                nd=nums[si];
            }
            si++;
        }

        // find min and max
        for(int i=0;i<nums.size();i++){
            if(nums[i]==st){
                maxn+='9';
            }
            else{
                maxn+=nums[i];
            }
            if(nums[i]==nd){
                minn+='0';
            }else{
                minn+=nums[i];
            }
        }

       return stoi(maxn)-stoi(minn);

    }
};