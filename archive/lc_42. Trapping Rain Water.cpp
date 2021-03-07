// Array, Two Pointer, Dynamic Programming, Stack

// stack 1
class Solution {
public:
    int trap(vector<int>& height) {
        vector<vector<int>::iterator> st;
        int ans = 0;
        for (auto it=height.begin(); it!=height.end(); ++it) {
            while (!st.empty() && *st.back() <= *it) {
                if (st.size() >= 2)
                    ans += (min(*it, *st[st.size()-2]) - *st.back()) * (it - st[st.size()-2] - 1);
                st.pop_back();
            }
            st.push_back(it);
        }
        return ans;
    }
};

// stack 2
class Solution {
public:
    int trap(vector<int>& H) {
        vector<int> st{0};
        int ans = 0;
        for (int i=1, n=H.size(); i<n; ++i) {
            while (!st.empty() && H[st.back()] <= H[i]) {
                if (st.size() >= 2)
                    ans += ( min(H[st[st.size()-2]], H[i]) - H[st.back()] ) * (i - st[st.size()-2] - 1);
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};

// two pointer
class Solution {
public:
    int trap(vector<int>& H) {
        if (H.empty()) return 0;
        int mxl = H[0], mxr = H.back();
        int l = 1, r = H.size() - 2, ans = 0;
        while (l <= r) {
            if (mxl <= mxr) {
                mxl = max(mxl, H[l]);
                ans += max(0, min(mxl, mxr) - H[l]);
                ++l;
            } else {
                mxr = max(mxr, H[r]);
                ans += max(0, min(mxl, mxr) - H[r]);
                --r;
            }
        }
        return ans;
    }
};