// Backtracking， constructive

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List ans = new ArrayList<Integer>();
        for (int l=1, st=1, step=1, ed; l<=9; st=st*10 + ++l, step=step*10+1) {
            ed = st + (9 - l) * step;
            if (ed < low) continue;
            for (int i=st; i<=ed; i+=step)
                if (i >= low && i <= high) ans.add(i);
        }
        return ans;
    }
}