//Tree, BFS

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
class Solution {  // BFS
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        deque<TreeNode *> que{root};
        while (!que.empty()) {
            ans.emplace_back();
            auto ii = back_inserter(ans.back());
            for (int k=que.size(); k--; ) {
                auto &node = que.front();
                ii = node->val;
                if (node->left) que.push_back(node->left);
                if (node->right) que.push_back(node->right);
                que.pop_front();
            }
        }
        return ans;
    }
};