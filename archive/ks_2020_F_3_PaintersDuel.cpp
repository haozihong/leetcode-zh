#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
#define fi first
#define se second
using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;

constexpr int MXN = 6;
int N, S, RA, PA, RB, PB, Cn;
unordered_map<ll, signed char> dp[MXN][MXN*MXN][MXN*MXN];
char itor[MXN*MXN], itop[MXN*MXN], rptoi[MXN][MXN*2-1];
vector<vector<char>> g;
signed char ans;

bool can_move(ll state, char i1) {
    for (auto &i2 : g[i1])
        if (!(state & 1ll<<i2)) return true;
    return false;
}

signed char f(char i1, char i9, ll state) {
    auto &dpt = dp[S-1][i1][i9];
    if (dpt.count(state)) return dpt[state];
    if (!can_move(state, i1)) {
        if (!can_move(state, i9)) return dpt[state] = 0;
        else return dpt[state] = -f(i9, i1, state);
    }
    signed char res = -MXN*MXN;
    for (auto &i2 : g[i1])
        if (!(state & 1ll<<i2))
            res = max(res, (signed char)(1-f(i9,i2,state | 1ll<<i2)));
    return dpt[state] = res;
}

void solve() {
    ll state = 0;
    cin >> S >> RA >> PA >> RB >> PB >> Cn;
    char Ai = rptoi[RA-1][PA-1], Bi = rptoi[RB-1][PB-1];
    state |= 1ll<<Ai | 1ll<<Bi;
    for (int i=0, r, p; i<Cn; ++i) {
        cin >> r >> p;
        state |= 1ll<<rptoi[r-1][p-1];
    }
    g.assign(S*S, vector<char>());
    for (char r=0; r<S; ++r) {
        for (char p=0; p<r*2; ++p) {
            g[rptoi[r][p]].push_back(rptoi[r][p+1]);
            g[rptoi[r][p+1]].push_back(rptoi[r][p]);
        }
        if (r < S - 1)
            for (char p=0; p<r*2+1; p+=2) {
                g[rptoi[r][p]].push_back(rptoi[r+1][p+1]);
                g[rptoi[r+1][p+1]].push_back(rptoi[r][p]);
            }
    }
    ans = f(Ai, Bi, state);
    cout << ((int)ans) << endl;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    for (char r=0, i=0; r<MXN; ++r)
        for (char p=0; p<r*2+1; ++p) {
            itor[i] = r;
            itop[i] = p;
            rptoi[r][p] = i++;
        }

    int t; cin >> t;
    for (int i=1; i<=t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}