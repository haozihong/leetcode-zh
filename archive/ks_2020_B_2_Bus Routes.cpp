#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define f first
// #define s second
using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;


int N;
ll D, ans;
ll A[1010];

void solve() {
    ans = 0;
    cin >> N >> D;
    
    for (int i=0; i<N; ++i)
        cin >> A[i];
    ans = D;
    for (int i=N; i--; )
        ans -= ans % A[i];

    cout << ans << endl;
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