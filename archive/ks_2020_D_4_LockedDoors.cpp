#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define f first
// #define s second
using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;

constexpr int MXN = 1e5;
int N, Q, S, K, D[MXN], Di[MXN], ans[MXN];
unordered_map<int, vector<pair<int, int>>> Ss;

void solve() {
    cin >> N >> Q;
    for (int i=0; i<N-1; ++i)
        cin >> D[i];
    Ss.clear();
    for (int i=0; i<Q; ++i) {
        cin >> S >> K;
        if (K == 1) {
            ans[i] = S;
        } else {
            Ss[S-1].emplace_back(K-1, i);
        }
    }
    for (auto it=Ss.begin(); it!=Ss.end(); ++it)
        sort(it->second.begin(), it->second.end());
    
    iota(Di, Di + N - 1, 0);
    sort(Di, Di + N - 1, [](int x, int y) { return D[x] > D[y]; });

    for (auto it=Ss.begin(); it!=Ss.end(); ++it) {
        int l = 0, r = N - 1, p = it->first, sti;
        auto itk = it->second.rbegin(), itked = it->second.rend();
        for (int i=0, d; i<N-1; ++i) {
            d = Di[i];
            if (d < l || d >= r) continue;
            if (d < p) {  // [l..i]
                sti = r - l - (d - l);
                while (itk != itked && sti <= itk->first) {
                    ans[itk->second] = d - (itk->first - sti) + 1;
                    ++itk;
                }
                if (itk == it->second.rend()) break;
                l = d + 1;
            } else {  // (i..r]
                sti = r - l - (r - d - 1);
                while (itk != itked && sti <= itk->first) {
                    ans[itk->second] = d + (itk->first - sti) + 2;
                    ++itk;
                }
                if (itk == it->second.rend()) break;
                r = d;
            }
        }
    }

    for (int i=0; i<Q-1; ++i) cout << ans[i] << " ";
    cout << ans[Q-1] << endl;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    for (int i=1; i<=t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}