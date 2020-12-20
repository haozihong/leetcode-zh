// Stack

class Solution {
public:
    string decodeAtIndex(string &S, int K) {
        long long l = 0;
        for (auto c : S)
            if ('a' <= c && c <= 'z') {
                if (++l == K) return string(1, c);
            } else {
                c -= '0';
                if (l * c >= K) return decodeAtIndex(S, (K-1) % l + 1);
                l *= c;
            }
        return "";
    }
};

// after reading solution:
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int p = -1, n = S.length();
        long long l = 0;
        while (l < K) {
            if (isalpha(S[++p])) ++l;
            else l *= (S[p] - '0');
        }
        for (;; --p) {
            K %= l;
            if (K == 0 && isalpha(S[p])) return string(1, S[p]);
            if (isalpha(S[p])) --l;
            else l /= (S[p] - '0');
        }
        return "";
    }
};