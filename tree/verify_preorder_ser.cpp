class Solution {
public:
    bool isValidSerialization(string preorder) {
        int parent = 1;
        for(auto chr : preorder){
            if(parent<=0){
                return false;
            }
            if(chr==','){
                continue;
            }else if(chr!='#'){
                parent++;
            }else{
                parent--;
            }
        }

        return parent==0;
    }
};