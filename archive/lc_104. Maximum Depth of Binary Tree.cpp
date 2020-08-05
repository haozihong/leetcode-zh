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
class Solution1 {  // dfs recursive
public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

class Solution2 {  // dfs iterative
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<tuple<decltype(root), char, int>> st;
        st.emplace(root, 0, 1);
        int mx = 1;
        while (!st.empty()) {
            auto &[node, ci, depth] = st.top();
            if (ci == 2) {
                st.pop();
            } else {
                auto child = ci == 0 ? node->left : node-> right;
                if (child != nullptr) {
                    mx = max(mx, depth + 1);
                    st.emplace(child, 0, depth + 1);
                }
                ++ci;
            }
        }
        return mx;
    }
};

class Solution {  // bfs
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        deque<decltype(root)> que{root};
        int depth = 0;
        while (!que.empty()) {
            ++depth;
            for (int k=que.size(); k--; ) {
                auto &node = que.front();
                if (node->left) que.push_back(node->left);
                if (node->right) que.push_back(node->right);
                que.pop_front();
            }
        }
        return depth;
    }
};