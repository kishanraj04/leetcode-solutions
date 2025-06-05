class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> res(num1.length() + num2.length(), 0);
        
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int mul = n1 * n2 + res[i + j + 1];
                
                res[i + j + 1] = mul % 10;
                res[i + j] += mul / 10;
            }
        }

        string str = "";
        bool leadingZero = true;

        for (int i = 0; i < res.size(); i++) {
            if (leadingZero && res[i] == 0) continue;
            leadingZero = false;
            str += to_string(res[i]);
        }

        return str.empty() ? "0" : str;
    }
};
