class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        char current = 'a'; 
        
        for (char ch : word) {
            int diff = abs(ch - current);
            cout<<diff<<" ";
            int moveTime = min(diff, 26 - diff);
            time += moveTime + 1; 
            current = ch;
        }
        
        return time;
    }
};
