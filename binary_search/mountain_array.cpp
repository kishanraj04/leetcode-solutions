class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=1;
        int e=arr.size()-2;
        int m=0;
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]>arr[m+1] && arr[m]>arr[m-1]){
                return m;
            }
            if(arr[m]<arr[m+1]){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return m;
    }
};