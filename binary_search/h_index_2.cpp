class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = 0;
        int e = citations.size() - 1;
        int len = citations.size();

        while (s <= e) {
            int mid = (s+e)/ 2;
            if (citations[mid] == len - mid) {
                return len - mid;
            } else if (citations[mid] < len - mid) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return len - s; 
    }
};
