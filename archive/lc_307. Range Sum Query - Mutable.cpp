// Segment Tree, Binary Indexed Tree

//Segment Tree:
class NumArray1 {
public:
    int n;
    vector<int> d, b;
    
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        n = nums.size();
        d.assign((1<<int( ceil(log2(n) + 1) )) + 1, 0);
        b.assign(d.size(), 0);
        build(0, n-1, 1, nums);
    }
    
    void build(int s, int t, int p, const vector<int> &a) {
        if (s == t) {
            d[p] = a[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p*2, a);
        build(m+1, t, p*2+1, a);
        d[p] = d[p*2] + d[p*2+1];
    }
    
    void update(int i, int val, int s=0, int t=-1, int p=1) {
        if (t == -1) t = n-1;
        if (i == s && s == t) {
            d[p] = val;
            return;
        }
        int m = s + (t - s) / 2;
        if (b[p]) {
            d[p*2] += b[p]; d[p*2+1] += b[p];
            b[p*2] += b[p]; b[p*2+1] += b[p];
            b[p] = 0;
        }
        if (i <= m) update(i, val, s, m, p*2);
        else update(i, val, m+1, t, p*2+1);
        d[p] = d[p*2] + d[p*2+1];
    }
    
    int sumRange(int i, int j, int s=0, int t=-1, int p=1) {
        if (t == -1) t = n-1;
        if (i <= s && t <= j) return d[p];
        int m = s + (t - s) / 2;
        if (b[p]) {
            d[p*2] += b[p]; d[p*2+1] += b[p];
            b[p*2] += b[p]; b[p*2+1] += b[p];
            b[p] = 0;
        }
        int res = 0;
        if (i <= m) res = sumRange(i, j, s, m, p*2);
        if (m < j) res += sumRange(i, j, m+1, t, p*2+1);
        return res;
    }
};

// Binary Indexed Tree
class NumArray {
public:
    int n;
    vector<int> a, c;
    
    NumArray(vector<int>& nums): a(nums) {
        n = a.size();
        a.insert(a.begin(), 0);
        c.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            c[i] += a[i];
            int j = i + (i & -i);
            if (j <= n) c[j] += c[i];
        }
    }
    
    void update(int i, int val) {
        ++i;
        int d = val - a[i];
        a[i] = val;
        while (i <= n) c[i] += d, i += i & -i;
    }
    
    int pre_sum(int i) {
        ++i;
        int res = 0;
        while (i) res += c[i], i -= i & -i;
        return res;
    }
    
    int sumRange(int i, int j) {
        return pre_sum(j) - (i ? pre_sum(i-1) : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */