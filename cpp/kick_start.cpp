#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

int A[500001];

void solve() {
    int N, K;
    cin >> N >> K;
    int mx = 0;
    cin >> A[0];
    for (int i=1; i<N; ++i) {
        cin >> A[i];
        A[i-1] = A[i] - A[i-1];
        mx = max(mx, A[i-1]);
    }
    int l = 1, r = mx, m;
    while (l < r) {
        m = (l + r) / 2;
        int k = 0;
        for (int i=0; i<N-1; ++i)
            k += ceil((double) A[i] / m) - 1;
        if (k <= K) r = m;
        else l = m + 1;
    }
    cout << l << endl;
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