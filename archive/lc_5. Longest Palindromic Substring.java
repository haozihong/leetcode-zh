// String, Dynamic Programming (d)
// Manacher's Algorithm

class Solution {
    public String longestPalindrome(String s) {
        char[] cs = new char[s.length()*2+1];
        for (int i=0, l=s.length(); i<l; ++i) {
            cs[i*2] = '#';
            cs[i*2+1] = s.charAt(i);
        }
        cs[cs.length-1] = '#';
        int [] d = new int[cs.length];
        int pre = 0, mxi = 0;
        for (int i=1, l=cs.length; i<l; ++i) {
            if (i <= pre + d[pre]) {
                int mi = pre - (i - pre);
                if (i + d[mi] != pre + d[pre]) {
                    d[i] = Math.min(d[mi], pre + d[pre] - i);
                } else {
                    d[i] = d[mi];
                    while (i-d[i]>0 && i+d[i]+1<l && cs[i-d[i]-1] == cs[i+d[i]+1]) ++d[i];
                }
            } else {
                while (i-d[i]>0 && i+d[i]+1<l && cs[i-d[i]-1] == cs[i+d[i]+1]) ++d[i];
            }
            if (i + d[i] > pre + d[pre]) pre = i;
            if (d[i] > d[mxi]) mxi = i;
        }
        return s.substring((mxi-d[mxi])/2, (mxi+d[mxi])/2);
    }
}