// Linked List, Recursion

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        vector<ListNode*> tail9;
        auto p = head;
        while (p) {
            if (p->val == 9) tail9.push_back(p); else tail9.assign({p});
            p = p->next;
        }
        for (int i=tail9.size()-1; i>0; --i)
            tail9[i]->val = 0;
        ++tail9[0]->val;
        if (head->val == 10) head->val = 0, head = new ListNode(1, head);
        return head;
    }
};