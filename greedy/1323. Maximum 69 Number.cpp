class Solution {

int ans = 0;
int c = 1;
int solv(int num,int digit){
    if(num<=0) return 0;
    digit = num%10;
    num/=10;
    solv(num,digit);
    if(digit==6 && c){
         ans = ans*10+9;
        c--;
    }else{
        ans = ans*10+digit;
    }
    return ans;
}

public:
    int maximum69Number (int num) {
        return solv(num,-1);
        
    }
};