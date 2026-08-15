class Solution {
public:
    string intToRoman(int num) {
        // Define mappings for all standard and subtractive cases
        struct RomanMapping {
            int value;
            string symbol;
        };
        
        vector<RomanMapping> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        
        for (const auto& mapping : romanMap) {
            // While the current value can be subtracted from num
            while (num >= mapping.value) {
                result += mapping.symbol;
                num -= mapping.value;
            }
        }
        
        return result;
    }
};