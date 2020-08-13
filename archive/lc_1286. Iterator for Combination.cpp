// Backtracking, Design, Combination

class CombinationIterator {
private:
    int n, l;
    string s;
    vector<int> a;
public:
    CombinationIterator(string s, int l): l(l), a(l), s(s), n(s.length()) {
        iota(a.begin(), a.end(), 0);
    }
    
    string next() {
        string res;
        transform(a.begin(), a.end(), back_inserter(res), [this](int i) { return s[i]; });
        ++a[l-1];
        int i = l - 1;
        while (i > 0 && a[i] > i + n - l) ++a[--i];
        while (++i < l) a[i] = a[i-1] + 1;
        return res;
    }
    
    bool hasNext() {
        return a[l-1] < n;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */