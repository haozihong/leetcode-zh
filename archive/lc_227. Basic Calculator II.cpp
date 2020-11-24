// String, Stack

class Solution1 {
public:
    unordered_map<char, function<int(int,int)>> fs = {
        {'+', [](int x, int y) { return x + y; }},
        {'-', [](int x, int y) { return x - y; }},
        {'*', [](int x, int y) { return x * y; }},
        {'/', [](int x, int y) { return x / y; }}
    };
    
    int calculate(string s) {
        vector<int> sn;   // stack of numbers
        vector<char> so;  // stack of operators
        sn.push_back(0);
        s += "$";
        for (auto &c : s) {
            if ('0' <= c && c <= '9') {
                sn.back() = sn.back() * 10 + (c - '0');
            } else if (c != ' ') {
                if (!so.empty() && (so.back() == '*' || so.back() == '/')) {
                    sn[sn.size()-2] = fs[so.back()](sn[sn.size()-2], sn.back());
                    sn.pop_back();
                    so.pop_back();
                }
                if (c != '$') so.push_back(c), sn.push_back(0);
            }
        }
        for (int i=0, n=so.size(); i<n; ++i)
            sn[i+1] = fs[so[i]](sn[i], sn[i+1]);
        return sn.back();
    }
};

class Solution {
public:
    unordered_map<char, function<int(int,int)>> fs = {
        {'+', [](int x, int y) { return x + y; }},
        {'-', [](int x, int y) { return x - y; }},
        {'*', [](int x, int y) { return x * y; }},
        {'/', [](int x, int y) { return x / y; }}
    };
    
    int calculate(string s) {
        list<int> A;
        A.push_back(0);
        for (auto &c : s) {
            if ('0' <= c && c <= '9') A.back() = A.back() * 10 + (c - '0');
            else if (c != ' ') A.push_back(c), A.push_back(0);
        }
        for (auto it=next(A.begin()); it!=A.end();) {
            if (*it == '*' || *it == '/') {
                *it = fs[*it](*prev(it), *next(it));
                A.erase(prev(it));
                A.erase(next(it));
                ++it;
            } else {
                advance(it, 2);
            }
        }
        while (A.size() > 1) {
            A.front() = fs[*(next(begin(A)))](A.front(), *(next(begin(A), 2)));
            A.erase(next(begin(A)), next(begin(A), 3));
        }
        return A.front();
    }
};