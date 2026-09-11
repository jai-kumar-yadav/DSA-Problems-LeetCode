#include <vector>
#include <unordered_set>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) {
            count[d]++;
        }
        
        int distinctCount = 0;
        
        for (int num = 100; num <= 998; num += 2) {
            int h = num / 100;
            int t = (num / 10) % 10;
            int u = num % 10;
            
            int tempCount[10] = {0};
            tempCount[h]++;
            tempCount[t]++;
            tempCount[u]++;
            
            bool possible = true;
            for (int i = 0; i <= 9; i++) {
                if (tempCount[i] > count[i]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                distinctCount++;
            }
        }
        
        return distinctCount;
    }
};