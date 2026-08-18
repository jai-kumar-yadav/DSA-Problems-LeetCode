class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int prevValue = 0;
        
        // Traverse from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentValue = values[s[i]];
            
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            
            prevValue = currentValue;
        }
        
        return total;
    }
};