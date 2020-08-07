// Hash Table, Tree, BFS, 

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> vt;
        deque<pair<TreeNode *, int>> que;
        que.emplace_back(root, 0);
        while (!que.empty()) {
            map<int, set<int>> tmp;
            for (int k=que.size(); k--; ) {
                auto &[node, x] = que.front();
                tmp[x].insert(node->val);
                if (node->left) que.emplace_back(node->left, x-1);
                if (node->right) que.emplace_back(node->right, x+1);
                que.pop_front();
            }
            for (auto &item : tmp)
                move(item.second.begin(), item.second.end(), back_inserter(vt[item.first]));
        }
        vector<vector<int>> ans;
        for (auto &item : vt) ans.push_back(move(item.second));
        return ans;
    }
};