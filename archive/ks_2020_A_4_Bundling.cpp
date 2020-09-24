#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define f first
// #define s second
using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;


struct TrieNode {
    int cnt = 0;
    int child[26];
    void init() {
        cnt = 0;
        fill_n(child, 26, 0);
    }
} static trie[2000001];

int tl = 0;

void add_word(string& w) {
    int p = 0;
    for (auto c : w) {
        c -= 65;
        if (trie[p].child[c] == 0) {
            trie[tl].init();
            trie[p].child[c] = tl++;
        }
        p = trie[p].child[c];
        ++trie[p].cnt;
    }
}

void solve() {
    int N, K;
    cin >> N >> K;
    
    trie[0].init();
    tl = 1;

    string w;
    for (int i=0; i<N; ++i) {
        cin >> w;
        add_word(w);
    }
    int ans = 0;
    for (int i=0; i<tl; ++i)
        ans += trie[i].cnt / K;
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