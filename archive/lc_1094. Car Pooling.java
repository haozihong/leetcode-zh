// Greedy

class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] change = new int[1001];
        int mn = 1000, mx = 0;
        for (int[] t : trips) {
            change[t[1]] += t[0];
            change[t[2]] -= t[0];
            if (t[1] < mn) mn = t[1];
            if (t[2] > mx) mx = t[2];
        }
        int cnt = 0;
        for (int i=mn; i<=mx; ++i)
            if ((cnt += change[i]) > capacity) return false;
        return true;
    }
}