class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int llv = 1;
        int ctv = 0;
        while(ctv<label){
            ctv+=llv;
            llv*=2;
        }
        llv/=2;

        vector<int> res;
        while(label!=1){
            res.push_back(label);
            int comp = (3*llv-label-1);
            int p = comp/2;
            label=p;
            llv/=2;
        }
        res.push_back(1);
        reverse(res.begin(),res.end());
        return res;
    }
};