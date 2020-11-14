// Ordered Map, Sorted Disjoint Intervals

class RangeModule {
public:
    vector<int> I;  // intervals
    int tmp[2];
    
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto p = lower_bound(begin(I), end(I), left),
             q = upper_bound(begin(I), end(I), right);
        auto qt = tmp;
        if ((p - begin(I)) % 2 == 0) *(qt++) = left;
        if ((q - begin(I)) % 2 == 0) *(qt++) = right;
        auto pt = tmp;
        while (p != q && pt != qt) *(p++) = *(pt++);
        p = I.erase(p, q);
        I.insert(p, pt, qt);
    }
    
    bool queryRange(int left, int right) {
        auto p = upper_bound(begin(I), end(I), left);
        return (p - begin(I)) % 2 == 1 && *p >= right;
    }
    
    void removeRange(int left, int right) {
        auto p = lower_bound(begin(I), end(I), left),
             q = upper_bound(begin(I), end(I), right);
        auto qt = tmp;
        if ((p - begin(I)) % 2 == 1) *(qt++) = left;
        if ((q - begin(I)) % 2 == 1) *(qt++) = right;
        auto pt = tmp;
        while (p != q && pt != qt) *(p++) = *(pt++);
        p = I.erase(p, q);
        I.insert(p, pt, qt);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */