// 1335. Minimum Difficulty of a Job Schedule

class Solution {
    int rmq(int l, int r, int[][] f) {  // maximum
        int lg = (int) (Math.log(r-l+1)/Math.log(2));
        return Math.max(f[l][lg], f[r-(1<<lg)+1][lg]);
    }

    public int minDifficulty(int[] A, int d) {
        if (d > A.length) return -1;
        int n = A.length;

        int[][] f = new int[n][(int)Math.ceil(Math.log(n)/Math.log(2))+1];
        for (int i=0; i<n; ++i)
            f[i][0] = A[i];
        for (int j=1; j<f[0].length; ++j) {
            for (int i=0; i+(1<<(j-1))<n; ++i)
                f[i][j] = Math.max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
            for (int i=n-(1<<(j-1)); i<n; ++i)
                f[i][j] = f[i][j-1];
        }
        
        int[] dp = new int[n];
        for (int i=0; i<n-d+1; ++i)
            dp[i] = rmq(0, i, f);
        for (int k=1; k<d; ++k) {
            for (int i=n-d+k; i>=k; --i) {
                dp[i] = dp[i-1] + A[i];
                for (int j=i-1; j>=k; --j)
                    dp[i] = Math.min(dp[i], dp[j-1] + rmq(j, i, f));
            }
        }
        return dp[n-1];
    }
}