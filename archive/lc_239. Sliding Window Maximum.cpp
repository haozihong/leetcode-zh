// Heap, Sliding Window, Dequeue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<int> que;
        vector<int> ans;
        for (int i=0, n=A.size(); i<n; ++i) {
            while (!que.empty() && A[que.back()] <= A[i]) que.pop_back();
            que.push_back(i);
            while (que.front() <= i - k) que.pop_front();
            if (i >= k-1) ans.push_back(A[que.front()]);
        }
        return ans;
    }
};