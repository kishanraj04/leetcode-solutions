class Solution {
public:
    int reachNumber(int target) {
        long long move=1;
        long long cm=0;
        target = abs(target);
        while(cm!=target){
            cm+=move;
            if(cm==target){
                return move;
            }else if(cm>target){
                if((abs(cm-target))%2==0){
                    return move;
                }else{
                    move++;
                }
            }else{
                move++;
            }
        }
        return move;
    }
};