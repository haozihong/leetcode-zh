// Tree, DFS, iterative, recursive

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
    bool isValidBST(TreeNode* p, TreeNode* mn=nullptr, TreeNode* mx=nullptr) {
        if (!p) return true;
        if ((mn && p->val <= mn->val) || (mx && p->val >= mx->val)) return false;
        return isValidBST(p->left, mn, p) && isValidBST(p->right, p, mx);
    }
};

class Solution {  // iterative 这也太麻烦了
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode *> stp, stl, str;
        stp.emplace(root); stl.emplace(nullptr); str.emplace(nullptr);
        while (!stp.empty()) {
            for (auto p=stp.top(), l=stl.top(), r=str.top(); p->left || p->right; ) {
                if (p->left) {
                    r = p;
                    p = p->left;
                } else {
                    l = p;
                    p = p->right;
                }
                if ((l && p->val <= l->val) || (r && p->val >= r->val)) return false;
                stp.emplace(p); stl.emplace(l); str.emplace(r);
            }
            for (TreeNode *prev=nullptr;
                 !stp.empty() && (prev!=stp.top()->left || !stp.top()->right); )
                prev = stp.top(), stp.pop(), stl.pop(), str.pop();
            if (!stp.empty()) {
                auto p = stp.top()->right, l = stp.top(), r = str.top();
                if ((l && p->val <= l->val) || (r && p->val >= r->val)) return false;
                stp.emplace(p); stl.emplace(l); str.emplace(r);
            }
        }
        return true;
    }
};