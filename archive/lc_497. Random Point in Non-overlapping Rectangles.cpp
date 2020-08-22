// Random, Binary Search

// works for overlapping rectangles
// but actually rectangles are non-overlapping in this problem. Damn
// see the other version below this
class Solution {
public:
    vector<int> xs, ys, ss;
    vector<tuple<int, int>> candi; // x, y
    
    Solution(vector<vector<int>>& rects) {
        set<int> xss, yss;
        for (auto &rc : rects) {
            xss.insert(rc[0]); xss.insert(rc[2] + 1);
            yss.insert(rc[1]); yss.insert(rc[3] + 1);
        }
        xs.assign(begin(xss), end(xss));
        ys.assign(begin(yss), end(yss));
        unordered_map<int, int> xi, yi;
        int im = 0, in = 0;
        for (auto &x : xs) xi[x] = im++;
        for (auto &y : ys) yi[y] = in++;
        unordered_set<int> grids;
        for (auto &rc : rects) {
            for (int i=xi[rc[0]], ir=xi[rc[2]+1]; i<ir; ++i)
                for (int j=yi[rc[1]], jr = yi[rc[3]+1]; j<jr; ++j)
                    grids.insert(i * in + j);
        }
        candi.clear(); ss.assign({0});
        for (auto &idx : grids) {
            int i = idx / in, j = idx % in, sz = (xs[i+1] - xs[i]) * (ys[j+1] - ys[j]);
            ss.push_back(ss.back() + sz);
            candi.emplace_back(i, j);
        }
    }
    
    vector<int> pick() {
        int idx = rand() % ss.back();
        int i = upper_bound(begin(ss), end(ss), idx) - begin(ss) - 1;
        idx -= ss[i];
        auto [xi, yj] = candi[i];
        int h = ys[yj+1] - ys[yj];
        return {xs[xi] + idx / h, ys[yj] + idx % h};
    }
};


// this version works for non-overlapping rectangles
class Solution {
public:
    vector<int> ss;
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>>& rects): rects(rects), ss{0} {
        for (auto &rc : rects)
            ss.push_back(ss.back() + (rc[2] - rc[0] + 1) * (rc[3] - rc[1] + 1));
    }
    
    vector<int> pick() {
        int idx = rand() % ss.back();
        int i = upper_bound(begin(ss), end(ss), idx) - begin(ss) - 1;
        idx -= ss[i];
        int h = rects[i][3] - rects[i][1] + 1;
        return {rects[i][0] + idx / h, rects[i][1] + idx % h};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */