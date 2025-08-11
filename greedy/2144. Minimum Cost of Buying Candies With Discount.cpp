class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int mincost = 0;
        sort(cost.rbegin(),cost.rend());

        for(int i=0;i<cost.size();i+=3){
            if(i+1<cost.size()){
                mincost+=cost[i]+cost[i+1];
            }else{
                 mincost+=cost[i];
            }
        }
        return mincost;
    }
};