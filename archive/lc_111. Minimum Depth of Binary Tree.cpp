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

class Solution2 {  // DFS recursion
public:
    void dfs(TreeNode *node, int depth, int &mn_depth) {
        if (node == nullptr || depth >= mn_depth) return;
        if (node->left == nullptr && node->right == nullptr) {
            mn_depth = depth;
            return;
        }
        dfs(node->left, depth + 1, mn_depth);
        dfs(node->right, depth + 1, mn_depth);
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int mn_depth = INT_MAX;
        dfs(root, 1, mn_depth);
        return mn_depth;
    }
};

class Solution {  // DFS iteration
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