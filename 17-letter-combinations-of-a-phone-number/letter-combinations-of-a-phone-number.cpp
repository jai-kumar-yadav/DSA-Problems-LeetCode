class Solution {
private:
    const vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(int index, const string& digits, string& current, vector<string>& result) {
        // Base case: if the current combination is of the same length as digits
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the string corresponding to the current digit
        char digit = digits[index];
        string letters = mapping[digit - '0'];

        // Try every letter corresponding to the digit
        for (char letter : letters) {
            current.push_back(letter);       // Choose
            backtrack(index + 1, digits, current, result); // Explore
            current.pop_back();              // Un-choose (backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string current = "";
        backtrack(0, digits, current, result);
        return result;
    }
};