// Sort, Tree, Binary Search Tree, BST

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
    void add_left_chain(vector<TreeNode*> &st, TreeNode *p) {
        while (p) {
            st.push_back(p);
            p = p->left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> st1, st2;
        add_left_chain(st1, root1);
        add_left_chain(st2, root2);
        vector<int> ans;
        while (!st1.empty() || !st2.empty()) {
            auto &st = st2.empty() || (!st1.empty() && st1.back()->val <= st2.back()->val) ? st1 : st2;
            ans.push_back(st.back()->val);
            auto p = st.back();
            st.pop_back();
            add_left_chain(st, p->right);
        }
        return ans;
    }
};