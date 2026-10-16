#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    long long tree[400005];
    long long lazy[400005];
    long long sum_val[400005];
    int MOD = 1e9 + 7;

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            long long val = lazy[node];
            int mid = (l + r) / 2;
            
            // Update left child
            long long left_len = (mid - l + 1);
            tree[2 * node] = (tree[2 * node] + 2 * sum_val[2 * node] % MOD * val % MOD + val * val % MOD * left_len % MOD) % MOD;
            sum_val[2 * node] = (sum_val[2 * node] + val * left_len % MOD) % MOD;
            lazy[2 * node] = (lazy[2 * node] + val) % MOD;

            // Update right child
            long long right_len = (r - mid);
            tree[2 * node + 1] = (tree[2 * node + 1] + 2 * sum_val[2 * node + 1] % MOD * val % MOD + val * val % MOD * right_len % MOD) % MOD;
            sum_val[2 * node + 1] = (sum_val[2 * node + 1] + val * right_len % MOD) % MOD;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;

            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            long long len = (r - l + 1);
            tree[node] = (tree[node] + 2 * sum_val[node] % MOD + len) % MOD;
            sum_val[node] = (sum_val[node] + len) % MOD;
            lazy[node] = (lazy[node] + 1) % MOD;
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
        sum_val[node] = (sum_val[2 * node] + sum_val[2 * node + 1]) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < 4 * n; ++i) {
            tree[i] = 0;
            lazy[i] = 0;
            sum_val[i] = 0;
        }

        unordered_map<int, int> last_seen;
        long long total_sum = 0;
        long long current_sum = 0;

        for (int i = 0; i < n; ++i) {
            int last = last_seen.count(nums[i]) ? last_seen[nums[i]] : -1;
            update(1, 0, n - 1, last + 1, i);
            last_seen[nums[i]] = i;
            
            long long sub_sum = query(1, 0, n - 1, 0, i);
            total_sum = (total_sum + sub_sum) % MOD;
        }

        return total_sum;
    }
};