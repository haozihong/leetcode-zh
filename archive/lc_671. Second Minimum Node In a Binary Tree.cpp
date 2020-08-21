// Tree, queue, BFS
// 即找树中比root大的节点中最小的，即找到每个子树中比root大的最小的节点、再找其中最小的
// 若一个子树的根比root大，那这就是这个子树里要找的点；
// 若一个子树的根和root一样大，则继续到它的子树里找。


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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int mn = -1;
        deque<TreeNode *> que{root};
        while (!que.empty()) {
            auto &node = que.front();
            if (node->val != root->val) {
                if (mn == -1 || node->val < mn) mn = node->val;
            } else {
                if (node->left) que.push_back(node->left);
                if (node->right) que.push_back(node->right);
            }
            que.pop_front();
        }
        return mn;
    }
};