// Binary Search Tree, BST, iterative, recursive

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
    void push_left_chain(vector<TreeNode*> &st, TreeNode *p) {
        while (p) {
            st.push_back(p);
            p = p->left;
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> st;
        push_left_chain(st, root);
        int s = 0;
        while (!st.empty()) {
            s += st.back()->val;
            auto p = st.back()->right;
            st.pop_back();
            if (p) push_left_chain(st, move(p));
        }
        push_left_chain(st, root);
        while (!st.empty()) {
            s -= st.back()->val;
            st.back()->val += s;
            auto p = st.back()->right;
            st.pop_back();
            if (p) push_left_chain(st, move(p));
        }
        return root;
    }
};

class Solution {  // recursive
public:
    void dfs1(TreeNode *p, int &s) {
        if (p->left) dfs1(p->left, s);
        s += p->val;
        if (p->right) dfs1(p->right, s);
    }
    
    void dfs2(TreeNode *p, int &s) {
        if (p->left) dfs2(p->left, s);
        s -= p->val;
        p->val += s;
        if (p->right) dfs2(p->right, s);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> st;
        int s = 0;
        dfs1(root, s);
        dfs2(root, s);
        return root;
    }
};