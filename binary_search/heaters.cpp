class Solution {
public:
    // Binary Search Floor: largest heater <= house
    int binarySearchFloor(const vector<int>& heater, int house) {
        int s = 0;
        int e = heater.size() - 1;
        int floor = -1;

        while (s <= e) {
            int m = s + (e - s) / 2;
            if (heater[m] == house) {
                return heater[m];
            } else if (heater[m] > house) {
                e = m - 1;
            } else {
                floor = heater[m];
                s = m + 1;
            }
        }
        return floor;
    }

    // Binary Search Ceil: smallest heater >= house
    int binarySearchCeil(const vector<int>& heater, int house) {
        int s = 0;
        int e = heater.size() - 1;
        int ceil = -1;

        while (s <= e) {
            int m = s + (e - s) / 2;
            if (heater[m] == house) {
                return heater[m];
            } else if (heater[m] > house) {
                ceil = heater[m];
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ceil;
    }

    // Main function
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;

        for (int i = 0; i < houses.size(); i++) {
            int house = houses[i];
            int floor = binarySearchFloor(heaters, house);
            int ceil = binarySearchCeil(heaters, house);

            if (floor == -1) floor = ceil;
            if (ceil == -1) ceil = floor;

            int dist = min(abs(house - floor), abs(house - ceil));
            ans = max(ans, dist); 
        }

        return ans;
    }
};
