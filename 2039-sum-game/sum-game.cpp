#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQuestionMarks = 0, rightQuestionMarks = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                leftQuestionMarks++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                rightQuestionMarks++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Alice wins if the total number of question marks is odd.
        if ((leftQuestionMarks + rightQuestionMarks) % 2 != 0) {
            return true; 
        }

        // Bob can only win if the sum difference exactly balances 
        // the average shift possible from the excess '?' on one side.
        // Formula: (leftSum - rightSum) == (rightQuestionMarks - leftQuestionMarks) * 9 / 2
        return (leftSum - rightSum) != (rightQuestionMarks - leftQuestionMarks) * 9 / 2;
    }
};