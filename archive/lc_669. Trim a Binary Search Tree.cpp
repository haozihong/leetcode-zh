// Tree, Recursion

// regular way
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high, TreeNode **pptr = nullptr) {
        if (root == nullptr) return nullptr;
        if (pptr == nullptr) pptr = &root;
        if (root->val < low) *pptr = root->right, trimBST(*pptr, low, high, pptr);
        else if (root->val > high) *pptr = root->left, trimBST(*pptr, low, high, pptr);
        else trimBST(root->left, low, high, &root->left), trimBST(root->right, low, high, &root->right);
        return *pptr;
    }
};

// interesting hack
class Solution {
public:
    TreeNode* trimBST(TreeNode*& root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low) root = root->right, trimBST(root, low, high);
        else if (root->val > high) root = root->left, trimBST(root, low, high);
        else trimBST(root->left, low, high), trimBST(root->right, low, high);
        return root;
    }
};