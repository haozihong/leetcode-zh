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
class Solution1 {  // DFS recursive
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (p == nullptr) == (q == nullptr) &&
            (p == nullptr || 
             (
                 p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)
             ));
    }
};

class Solution {  // BFS iterative
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return p == q;
        deque<TreeNode *> que1{p}, que2{q};
        while (que1.size() == que2.size() && !que1.empty()) {
            p = que1.front(); q = que2.front();
            if (p == nullptr) {
                if (q != nullptr) return false;
            } else {
                if (q == nullptr || p->val != q->val) return false;
                que1.insert(que1.end(), {p->left, p->right});
                que2.insert(que2.end(), {q->left, q->right});
            }
            que1.pop_front(); que2.pop_front();
        }
        return que1.size() == que2.size();
    }
};