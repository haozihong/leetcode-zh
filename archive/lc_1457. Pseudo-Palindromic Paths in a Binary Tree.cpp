// Bit Manipulation, Tree, Depth-first Search

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
public:
    int dfs(TreeNode* node, int cnt) {
        cnt ^= 1 << (node->val-1);
        if (!node->left && !node->right) return __builtin_popcount(cnt) <= 1;
        int t = 0;
        if (node->left) t += dfs(node->left, cnt);
        if (node->right) t += dfs(node->right, cnt);
        return t;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
};