// Greedy

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        for (int i=0; i<n; ++i) gas[i] -= cost[i];
        int ss = gas[0], mn = gas[0], mni = 0;
        for (int i=1; i<n; ++i) {
            ss += gas[i];
            if (ss < mn) { mn = ss; mni = i; }
        }
        return ss >= 0 ? (mni + 1) % n : -1;
    }
}