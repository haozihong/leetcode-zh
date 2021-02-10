// Tree, Depth-first Search, Binary Search Tree, Recursion

// 1. 
class Solution {
public:
    int trial(TreeNode *p, int s) {
        if (!p) return s;
        p->val += trial(p->right, s);
        return trial(p->left, p->val);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        trial(root, 0);
        return root;
    }
};

// 2. 
class Solution {
public:
    void trial(TreeNode *p, int &s) {
        if (!p) return;
        trial(p->right, s);
        p->val = s += p->val;
        trial(p->left, s);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        trial(root, s);
        return root;
    }
};