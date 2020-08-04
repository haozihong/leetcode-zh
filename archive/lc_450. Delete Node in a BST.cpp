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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        TreeNode dhead(0, root, nullptr);  // dummy head pointer
        auto prev = &dhead.left;
        auto p = root;
        while (p && p->val != key) {
            if (key < p->val) {
                prev = &p->left;
                p = p->left;
            } else {
                prev = &p->right;
                p = p->right;
            }
        }
        if (p && p->val == key) {
            if (p->left == nullptr) {          // left or both children are null
                *prev = p->right;
            } else if (p->right == nullptr) {  // right child is null
                *prev = p->left;
            } else {                           // neither one is null
                // find the biggest node in left subtree to replace the deleted
                auto prev2 = &p->left;
                auto q = p->left;
                while (q->right) {
                    prev2 = &q->right;
                    q = q->right;
                }
                *prev2 = q->left;
                q->left = p->left;
                q->right = p->right;
                *prev = q;
                delete p;
            }
        }
        return dhead.left;
    }
};