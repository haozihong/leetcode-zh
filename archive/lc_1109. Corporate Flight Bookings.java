// Array, Math, Interval

class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] count = new int[n];
        for (int[] b : bookings) {
            count[b[0]-1] += b[2];
            if (b[1] < n) count[b[1]] -= b[2];
        }
        for (int i=1; i<n; ++i)
            count[i] += count[i-1];
        return count;
    }
}