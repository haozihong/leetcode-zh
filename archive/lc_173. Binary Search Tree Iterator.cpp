// Stack, Tree, Design

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
class BSTIterator {
public:
    vector<TreeNode*> st;
    
    BSTIterator(TreeNode* root): st{root} {
        while (st.back()->left) st.push_back(st.back()->left);
    }
    
    int next() {
        auto tmp = st.back(); st.pop_back();
        if (tmp->right) {
            st.push_back(tmp->right);
            while (st.back()->left) st.push_back(st.back()->left);
        }
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */