//Tree, DFS, Stack

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
class Solution1 {  // recursive
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans{root->val};
        auto tmp = preorderTraversal(root->left);
        move(tmp.begin(), tmp.end(), back_inserter(ans));
        tmp = preorderTraversal(root->right);
        move(tmp.begin(), tmp.end(), back_inserter(ans));
        return ans;
    }
};

class Solution {  // iterative
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode *> st;
        auto p = root;
        while (p || !st.empty()) {
            if (p) {
                ans.push_back(p->val);
                st.push(p);
                p = p->left;
            } else {
                p = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};