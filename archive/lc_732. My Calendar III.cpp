// Segment Tree, Ordered Map

class MyCalendarThree {
public:
    int mx = 1;
    map<int, int> I;  // intervals
    
    MyCalendarThree() {}
    
    int book(int st, int ed) {
        auto p = I.lower_bound(st);
        if (p->first != st) {
            I[st] = p == begin(I) ? 0 : (--p)->second;
            p = I.find(st);
        }
        auto q = I.lower_bound(ed);
        if (q->first != ed) {
            I[ed] = q == begin(I) ? 0 : (--q)->second;
            q = I.find(ed);
        }
        while (p != q) mx = max(mx, ++(p++)->second);
        return mx;
    }
};

class MyCalendarThree1 {  // slower. Boundary Count 
public:
    map<int, int> I;  // intervals
    
    MyCalendarThree() {}
    
    int book(int st, int ed) {
        ++I[st]; --I[ed];
        int k = 0, mx = 1;
        for (auto &i : I)
            mx = max(mx, k += i.second);
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */