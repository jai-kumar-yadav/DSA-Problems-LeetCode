class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedBitmask;
        
        // Mark reserved seats for each row using a bitmask (seats 2 to 9)
        for (const auto& r : reservedSeats) {
            int row = r[0] - 1;
            int seat = r[1];
            if (seat >= 2 && seat <= 9) {
                reservedBitmask[row] |= (1 << (seat - 2));
            }
        }
        
        // Rows with no reserved seats can hold 2 groups each
        int totalGroups = (n - reservedBitmask.size()) * 2;
        
        // Check blocks for rows with reservations
        // Left block: seats 2-5 -> mask: 0x0F (binary: 0000 1111)
        // Middle block: seats 4-7 -> mask: 0x3C (binary: 0011 1100)
        // Right block: seats 6-9 -> mask: 0xF0 (binary: 1111 0000)
        int leftMask = 0x0F;
        int middleMask = 0x3C;
        int rightMask = 0xF0;
        
        for (const auto& [row, mask] : reservedBitmask) {
            bool leftFree = (mask & leftMask) == 0;
            bool rightFree = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;
            
            if (leftFree && rightFree) {
                totalGroups += 2;
            } else if (leftFree || rightFree || middleFree) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};