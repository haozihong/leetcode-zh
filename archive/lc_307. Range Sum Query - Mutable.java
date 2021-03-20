// Binary Indexed Tree, Segment Tree

// Binary Indexed Tree (BIT)
class BIT {
    private int n;
    
    private int[] c;
    
    public BIT(int[] nums) {
        n = nums.length;
        c = new int[n + 1];
        for (int i=1; i<=n; ++i) {
            c[i] += nums[i-1];
            if (i + (i & -i) <= n) c[i + (i & -i)] += c[i];
        }
    }
    
    public void add(int p, int delta) {
        ++p;
        while (p <= n) {
            c[p] += delta;
            p += p & -p;
        }
    }
    
    public void update(int p, int v) {
        add(p, v - rangeSum(p, p));
    }
    
    public int rangeSum(int p) {
        ++p;
        int res = 0;
        while (p > 0) {
            res += c[p];
            p -= p & -p;
        }
        return res;
    }
    
    public int rangeSum(int l, int r) {
        return rangeSum(r) - (l == 0 ? 0 : rangeSum(l - 1));
    }
}

class NumArray {
    private BIT b;
    
    public NumArray(int[] nums) {
        b = new BIT(nums);
    }
    
    public void update(int index, int val) {
        b.update(index, val);
    }
    
    public int sumRange(int left, int right) {
        return b.rangeSum(left, right);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */