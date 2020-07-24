struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

typedef unordered_set<vector<int>, VectorHash> svi;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<char> par_t;  // 0 for left parenthese, 1 for right, 2 for other
        vector<int> par_n;  // when other string: index
        vector<string> other;
        for (int p=0, q=1, l=s.length(); q<=l; ++q)
            if (q==l || s[q]!=s[q-1]) {
                if (s[q-1]=='(' || s[q-1]==')') {
                    par_t.push_back(s[q-1]!='(');
                    par_n.push_back(q-p);
                } else if (!par_t.empty() && par_t.back()==2){
                    other.back() += s.substr(p, q-p);
                } else {
                    par_t.push_back(2);
                    par_n.push_back(other.size());
                    other.push_back(s.substr(p, q-p));
                }
                p = q;
            }
        int par_l = par_t.size();
        
        svi ansn;
        ansn.insert(par_n);
        for (int k=0; k<=1; ++k) {
            int st = !k ? 0:par_l-1, step = !k ? 1:-1, ed = !k ? par_l:-1;
            for (int i=st, t=0; i!=ed; i+=step) {
                if (par_t[i]==2) continue;
                t += par_t[i]==k ? par_n[i] : -par_n[i];
                if (t < 0) {
                    decltype(ansn) tmp;
                    for (auto par_n2 : ansn)
                        expand(par_n2, st, i+step, 1-k, -t, tmp, par_t);
                    ansn.swap(tmp);
                    t = 0;
                }
            }
        }

        vector<string> ans;
        ans.reserve(par_l);
        for (auto& par_n2 : ansn) {
            ans.push_back("");
            for (int i=0; i<par_l; ++i) {
                if (par_t[i]==2) ans.back().append(other[par_n2[i]]);
                else ans.back().append(par_n2[i], !par_t[i]?'(':')');
            }
        }
        return ans;
    }
    
    void expand(vector<int>& par_n, int l, int r, char par_f, int redu,
                svi& res, const vector<char>& par_t) {
        if (redu == 0) {
            res.insert(par_n);
            return;
        }
        if (l == r) return;
        for (int i=l, step=l<r?1:-1; i!=r; i+=step) {
            if (par_t[i] != par_f) continue;
            for (int k=0; k<=min(par_n[i], redu); ++k) {
                par_n[i] -= k;
                expand(par_n, i+step, r, par_f, redu-k, res, par_t);
                par_n[i] += k;
            }
        }
    }
};