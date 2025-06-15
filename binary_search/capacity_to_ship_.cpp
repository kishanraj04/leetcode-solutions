class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mincap = *max_element(weights.begin(), weights.end());
        int maxcap = accumulate(weights.begin(), weights.end(), 0); 
        int mid;

        while (mincap < maxcap) {
            mid = mincap + (maxcap - mincap) / 2;
            int currcap = 0;
            int currd = 1;

            for (int i = 0; i < weights.size(); i++) {
                if (currcap + weights[i] > mid) {
                    currd++;
                    currcap = 0;
                }
                currcap += weights[i];
            }

            if (currd > days) {
                mincap = mid + 1;
            } else {
                maxcap = mid;
            }
        }

        return mincap;
    }
};
