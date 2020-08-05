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
class Solution3 {  // BFS
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        deque<decltype(root)> que{root};
        for (int step=1; 1; ++step) {
            for (int i=que.size(); i--; ) {
                auto node = que.front();
                if (node->left == nullptr && node->right == nullptr) return step;
                que.pop_front();
                if (node->left) que.push_back(node->left);
                if (node->right) que.push_back(node->right);
            }
        }
    }
};

class Solution {  // DFS recursion
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) {
            return 1 + minDepth(root->right);
        } else if (!root->right) {
            return 1 + minDepth(root->left);
        } else {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
};

class Solution3 {  // DFS iteration
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int mn_depth = INT_MAX;
        stack<tuple<TreeNode *, int, char>> st;
        st.emplace(root, 1, 0);
        while (!st.empty()) {
            auto &[node, depth, child] = st.top();
            if (child == 2 || depth >= mn_depth) {
                st.pop();
            } else if (node->left == nullptr && node->right == nullptr) {
                mn_depth = depth;
                st.pop();
            } else {
                auto child_node = child == 0 ? node->left : node->right;
                if (child_node != nullptr) st.emplace(child_node, depth+1, 0);
                ++child;
            }
        }
        return mn_depth;
    }
};