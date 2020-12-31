// Array, Stack

class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        vector<int> st{-1};  // monotonic stack
        int mx = 0;
        for (int i=0, n=H.size(); i<=n; ++i) {
            while (st.back() != -1 && (i == n || H[i] <= H[st.back()]))
                mx = max(mx, H[st.back()] * (st.pop_back(), i - st.back() - 1));
            st.push_back(i);
        }
        return mx;
    }
};