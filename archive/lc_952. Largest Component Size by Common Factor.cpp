// Math, Union Find

// 2020-08-02. 316 ms
class UnionFind {
private:
    int n, cnt, mx;
    vector<int> id, sz;
    
public:
    UnionFind(int n): n(n), cnt(n), id(n), sz(n, 1), mx(1) {
        iota(id.begin(), id.end(), 0);
    }
    
    int find(int p) {
        if (id[p] != p) id[p] = find(id[p]);
        return id[p];
    }
    
    bool compare(int p, int q) { return find(p) == find(q); }
    
    void combine(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        --cnt;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
            mx = max(mx, sz[j]);
        } else {
            id[j] = i;
            sz[i] += sz[j];
            mx = max(mx, sz[i]);
        }
    }
    
    int max_set_size() { return mx; }
};

vector<int> prime = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
    103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
    199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int lng = A.size();
        UnionFind uf(lng);
        unordered_map<int, int> factor;
        int mx = 1;
        for (int i=0; i<lng; ++i) {
            int &a = A[i];
            for (auto it=prime.begin(); it!=prime.end() && *it<=a; ++it)
                if (a % *it == 0) {
                    if (factor.count(*it)) uf.combine(factor[*it], i);
                    else factor[*it] = i;
                    do a /= *it; while (a % *it == 0);
                }
            if (a > 1) {
                if (factor.count(a)) uf.combine(factor[a], i);
                else factor[a] = i;
            }
        }
        return uf.max_set_size();
    }
};


// 2020-08-30. 504 ms
// expect this to be faster, but not. 
const int PRIME[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        unordered_map<int, int> id, cnt;
        int mx = 1;
        function<int(int)> fid = [&](int p) mutable {
            return !id.count(p) ? id[p] = p : id[p] == id[id[p]] ? id[p] : id[p] = fid(id[p]); 
        };
        for (auto x : A) {
            if (x == 1) continue;
            int f1 = -1;
            for (auto p : PRIME) {
                if (p > x) break;
                if (x % p == 0) {
                    if (f1 == -1) {
                        fid(f1 = p);
                    } else if (fid(p) != fid(f1)) {
                        cnt[fid(f1)] += cnt[fid(p)];
                        id[fid(p)] = fid(f1);
                    }
                    while (x % p == 0) x /= p;
                }
            }
            if (f1 == -1) {  // x is a prime larger than 100000^.5
                fid(f1 = x);
            } else if (x > 1 && fid(x) != fid(f1)){
                cnt[fid(f1)] += cnt[fid(x)];
                id[fid(x)] = fid(f1);
            }
            mx = max(mx, ++cnt[fid(f1)]);
        }
        return mx;
    }
};