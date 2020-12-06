// Tree, Depth-first Search

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node dhead;  // dummy head
        auto cur = root;
        while (cur) {
            dhead.next = nullptr;
            auto pre = &dhead;
            while (cur) {
                if (cur->left) pre = pre->next = cur->left;
                if (cur->right) pre = pre->next = cur->right;
                cur = cur->next;
            }
            cur = dhead.next;
        }
        return root;
    }
};