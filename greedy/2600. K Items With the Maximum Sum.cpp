class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        
        int res = 0;
        while(k>0){
            int tmp = 0;
            if(numOnes>0){
                res+=(numOnes>k?k:numOnes);
                k-=numOnes;
                numOnes=0;
            }else if(numZeros>0){
                k-=numZeros;
                numZeros=0;
            }else if(numNegOnes>0){
              
                res=res-k;
                k-=numNegOnes;
                numNegOnes=0;
               
            }
            
        }
        return res;
    }
};