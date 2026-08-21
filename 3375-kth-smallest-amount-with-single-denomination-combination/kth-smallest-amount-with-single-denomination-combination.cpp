class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Optional optimization: filter out duplicate multiples
        // For instance, if we have [3, 6, 9], 6 and 9 are multiples of 3,
        // but keeping them is fine as long as LCM doesn't overflow, 
        // though removing redundant ones helps speed up bitmasking.
        
        long long left = 1, right = 1LL * coins[0] * k;
        long long ans = right;

        // Find the minimum coin to set a tight lower bound if needed
        long long min_coin = coins[0];
        for (int c : coins) {
            min_coin = min(min_coin, (long long)c);
        }
        right = min_coin * k;

        auto gcd = [](long long a, long long b) {
            while (b) {
                a %= b;
                swap(a, b);
            }
            return a;
        };

        auto lcm = [&](long long a, long long b) {
            return (a / gcd(a, b)) * b;
        };

        // Function to count how many numbers <= x can be formed using the coins
        auto count_amounts = [&](long long x) {
            long long total = 0;
            int n = coins.size();
            // Iterate over all subsets using bitmask
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int set_bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        set_bits++;
                        current_lcm = lcm(current_lcm, coins[i]);
                        if (current_lcm > x) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                if (set_bits % 2 == 1) {
                    total += x / current_lcm;
                } else {
                    total -= x / current_lcm;
                }
            }
            return total;
        };

        // Binary Search
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (count_amounts(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};