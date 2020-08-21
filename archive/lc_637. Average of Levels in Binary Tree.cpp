// Tree, 

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode *> que{root};
        vector<double> ans;
        double s = root->val;
        while (!que.empty()) {
            ans.push_back(s / que.size());
            s = 0;
            for (int k=que.size(); k--; ) {
                auto &p = que.front();
                if (p->left) que.push_back(p->left), s += p->left->val;
                if (p->right) que.push_back(p->right), s += p->right->val;
                que.pop_front();
            }
        }
        return ans;
    }
};