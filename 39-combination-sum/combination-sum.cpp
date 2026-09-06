class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue; // Pruning if the candidate exceeds the remaining target
            
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result); // Not i + 1 because we can reuse the same element
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};