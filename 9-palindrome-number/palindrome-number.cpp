class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending in 0 (except 0) aren't palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = (reversedHalf * 10) + (x % 10);
            x /= 10;
        }

        // For even length, x == reversedHalf. 
        // For odd length, x == reversedHalf / 10 (ignoring middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};