/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Helper function returns a pair: {sum_of_subtree, count_of_nodes}
    pair<int, int> postOrder(TreeNode* root, int& count) {
        if (!root) return {0, 0};

        auto left = postOrder(root->left, count);
        auto right = postOrder(root->right, count);

        int current_sum = root->val + left.first + right.first;
        int current_count = 1 + left.second + right.second;

        // Check if the average of the subtree equals the node's value
        if (current_sum / current_count == root->val) {
            count++;
        }

        return {current_sum, current_count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int valid_nodes_count = 0;
        postOrder(root, valid_nodes_count);
        return valid_nodes_count;
    }
};
