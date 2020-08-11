//Tree, DFS, BFS

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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || symmetric(root->left, root->right);
    }
    
    bool symmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr || q == nullptr) return p == q;
        if (p->val != q->val) return false;
        return symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }
};

class Solution2 {  // BFS iterative
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        deque<TreeNode *> que{root};
        while (!que.empty()) {
            for (int k=que.size(); k; --k) {
                auto &node = que.front();
                if (node) {
                    que.push_back(node->left);
                    que.push_back(node->right);
                }
                que.pop_front();
            }
            for (auto it1=que.begin(), it2=que.end()-1; it1<it2; ++it1, --it2)
                if (*it1 != *it2) {
                    if (*it1 == nullptr || *it2 == nullptr) return false;
                    else if ((*it1)->val != (*it2)->val) return false;
                }
        }
        return true;
    }
};

class Solution {  // DFS iterative
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        deque<TreeNode *> que{root};
        stack<TreeNode *> st1, st2;
        auto p = root->left, q = root->right;
        while (p || !st1.empty() || q || !st2.empty()) {
            if (!(p == q || (p && q && p->val == q->val))) return false;
            if (p) {
                st1.push(p);
                p = p->left;
            } else {
                p = st1.top()->right;
                st1.pop();
            }
            if (q) {
                st2.push(q);
                q = q->right;
            } else {
                q = st2.top()->left;
                st2.pop();
            }
        }
        return true;
    }
};