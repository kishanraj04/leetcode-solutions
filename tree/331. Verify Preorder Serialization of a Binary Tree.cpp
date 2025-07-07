#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int parent = 1; // Start with one slot for the root

        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {
            if (parent == 0) return false;

            if (node == "#") {
                parent--; 
            } else {
                
                parent += 1; 
            }
        }

        return parent == 0;
    }
};
