class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> m;
        map<int,int> f;
        for(int v:nums){
            m[v]+=1;
        }

            for(auto it=m.rbegin(); it!=m.rend();++it){
                k-=it->second;
                if(k<=0) return it->first;
            }
      
        return 0;
    }
};