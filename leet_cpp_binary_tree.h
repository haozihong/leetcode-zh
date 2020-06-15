#include<bits/stdc++.h>
#include"leet_cpp_tools.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string treeNodeToString(TreeNode* root);

TreeNode* stringToTreeNode(string input);

void prettyPrintTree(TreeNode* node, string prefix /*= ""*/, bool isLeft /*= true*/);