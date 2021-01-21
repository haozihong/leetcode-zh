// Stack, Heap, Greedy, Queue, Monotone Queue

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> que;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            while (!que.empty() && que.back() > nums[i]) que.pop_back();
            que.push_back(nums[i]);
            if (i >= n-k) ans.push_back(que[0]), que.pop_front();
        }
        return ans;
    }
};