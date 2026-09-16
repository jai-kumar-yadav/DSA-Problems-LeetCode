class Solution {
private:
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // Step 1: Build connected components using DSU
        for (const auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
        
        // Step 2: Group indices by their component root
        unordered_map<int, vector<int>> componentIndices;
        for (int i = 0; i < n; ++i) {
            componentIndices[find(i)].push_back(i);
        }
        
        int hammingDistance = 0;
        
        // Step 3: For each component, match source and target elements
        for (auto& [root, indices] : componentIndices) {
            unordered_map<int, int> countMap;
            
            // Count frequencies of elements in source for this component
            for (int idx : indices) {
                countMap[source[idx]]++;
            }
            
            // Subtract frequencies using elements from target
            for (int idx : indices) {
                if (countMap[target[idx]] > 0) {
                    countMap[target[idx]]--;
                } else {
                    // If the target element isn't available in this component, it adds to Hamming distance
                    hammingDistance++;
                }
            }
        }
        
        return hammingDistance;
    }
};