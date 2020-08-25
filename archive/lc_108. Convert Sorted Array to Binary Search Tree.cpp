// Tree, DFS, Iterative,

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
class Solution1 {  // iterative
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        auto root = new TreeNode();
        queue<tuple<TreeNode *, int, int>> que;
        que.emplace(root, 0, nums.size() - 1);
        while (!que.empty()) {
            auto &[node, l, r] = que.front();
            int m = (l + r + 1) / 2;
            node->val = nums[m];
            if (m > l) {
                node->left = new TreeNode();
                que.emplace(node->left, l, m-1);
            }
            if (m < r) {
                node->right = new TreeNode();
                que.emplace(node->right, m+1, r);
            }
            que.pop();
        }
        return root;
    }
};

class Solution {  // recursive
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l=0, int r=INT_MIN) {
        if (r == INT_MIN) r = nums.size() - 1;
        if (l > r) return nullptr;
        int m = (l + r + 1) / 2;
        return new TreeNode(nums[m], sortedArrayToBST(nums, l, m-1), sortedArrayToBST(nums, m+1, r));
    }
};