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
class Solution1 {  //DFS recursive
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        auto ans = postorderTraversal(root->left), rc = postorderTraversal(root->right);
        move(rc.begin(), rc.end(), back_inserter(ans));
        ans.push_back(root->val);
        return ans;
    }
};

class Solution {  //DFS iterative
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<pair<TreeNode *, char>> st;
        st.emplace(root, 0);
        vector<int> ans;
        while (!st.empty()) {
            auto &[node, ci] = st.top();
            if (ci == 2) {
                ans.push_back(node->val);
                st.pop();
            } else {
                auto child = ci == 0 ? node->left : node->right;
                if (child != nullptr) st.emplace(child, 0);
                ++ci;
            }
        }
        return ans;
    }
};