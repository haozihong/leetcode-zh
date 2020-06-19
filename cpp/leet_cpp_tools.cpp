#include <bits/stdc++.h>
#include "leet_cpp_tools.h"

using namespace std;

// int main() {
    // auto v1 = vector<int>({1,2,3});
    // print_vector(v1);
    
    // auto v2 = vector<vector<int>>({{1,2,3}, {2,3,4}});
    // print_vector(v2);
    
    // auto v3 = vector<vector<vector<int>>>({{{1,2,3}, {2,3,4}},{{3,5,7}, {4,6,8}}});
    // print_vector(v3);
    
    // print_vector(stringToVector<string>("[\"1\",\"2\"]"));
    // print_vector(stringToVector<int>("[1,2]"));
// }

// vector<int> stringToIntegerVector(string input) {
//     vector<int> output;
//     trimLeftTrailingSpaces(input);
//     trimRightTrailingSpaces(input);
//     input = input.substr(1, input.length() - 2);
//     stringstream ss;
//     ss.str(input);
//     string item;
//     char delim = ',';
//     while (getline(ss, item, delim)) {
//         output.push_back(stoi(item));
//     }
//     return output;
// }

/* int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
} */

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToVector<int>(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

/* int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        prettyPrintTree(root);
    }
    return 0;
} */
