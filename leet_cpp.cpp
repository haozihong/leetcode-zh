#include <bits/stdc++.h>
#include <cxxabi.h>
#include "leet_cpp_tools.h"

using namespace std;

// vector<int> testf() {
    // int a[] = {1,2,3,4,5};
    // vector<int> v (a, a + sizeof(a) / sizeof(int));
    // return v;
// }
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

ListNode *listIter(ListNode *p, int n) {
    while (n-- && p != nullptr) p = p->next;
    return p;
}

ListNode *listEnd(ListNode *p) {
    if (p == nullptr) return nullptr;
    while (p->next != nullptr) p = p->next;
    return p;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> e_out(n);
        vector<int> deg_in(n, 0);
        for (auto &c : prerequisites) {
            e_out[c[1]].push_back(c[0]);
            ++deg_in[c[0]];
        }
        vector<int> que;
        for (int i=0; i<n; ++i)
            if (deg_in[i] == 0) que.push_back(i);
        for (int i=0; i<que.size(); ++i) {
            for (auto &q : e_out[que[i]]) {
                --deg_in[q];
                if (deg_in[q] == 0) que.push_back(q);
            }
        }
        return que.size() == n;
    }
};

int main(void) {
#define INPUT_TYPE 1
#if INPUT_TYPE == 1     //written down inputs
	extern int in0;
    extern vector<vector<int>> in1;
    // extern vector<vector<int>> in2;

	auto ou = Solution().canFinish(in0, in1);
	// print_vector(ou);
    cout << ou << endl;
#elif INPUT_TYPE == 2   // input from keyboard
#define LIST_TYPE int
    string line;
    while (getline(cin, line)) {
        vector<LIST_TYPE> nums = stringToVector<LIST_TYPE>(line);
        
        int ret = Solution().numSquarefulPerms(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
#elif INPUT_TYPE == 3   // list inputs
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        // ListNode* l2 = stringToListNode(line);
        int m = stoT<int>(line);
        if (m >= 0) listEnd(l1)->next = listIter(l1, m);
        
        ListNode* ret = Solution().detectCycle(l1);

        if (ret != nullptr) cout << ret->val <<endl;
        // string out = listNodeToString(ret);
        // string out = treeNodeToString(ret);
        // cout << out << endl;
    }
#elif INPUT_TYPE == 4   // design class
    LFUCache cache(2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
#elif INPUT_TYPE == 5   // input from file
    // extern vector<string> in0;
    // extern vector<vector<string>> in1;
    enum keywords {TRIE, insert, search, startsWith};
    unordered_map<string, keywords> map;
    map["Trie"] = TRIE;
    map["insert"] = insert;
    map["search"] = search;
    map["startsWith"] = startsWith;
    Trie *trie;
    ifstream ifile0("in1_0.in"), ifile1("in1_1.in");
    string in0, in1;
    while (ifile0.peek() != EOF) {
        ifile0 >> in0; ifile1 >> in1;
        switch (map[in0]) {
            case TRIE:
                trie = new Trie();
                break;
            case insert:
                trie->insert(in1);
                break;
            case search: {
                auto ou = trie->search(in1);
                // cout << ou << endl;
                break;
            }
            case startsWith: {
                if (in1 == "physic") {
                   cout << "!" << endl;
                }
                auto ou = trie->startsWith(in1);
                // cout << ou << endl;
            }
        }
    }
#endif
}
