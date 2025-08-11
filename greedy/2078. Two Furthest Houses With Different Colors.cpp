class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size()-1;
        if(colors[0]!=colors[colors.size()-1]) return abs(0-n);

        // left most
        while(n>=0 && colors[n]==colors[0]){
            n--;
        }

        int md1 = abs(0-n);
        n=colors.size()-1;

        // right most
        int i=0;
        while(i<=n && colors[i]==colors[n]){
            i++;
        }
        int md2 = abs(i-n);
        
        return max(md1,md2);
    }
};