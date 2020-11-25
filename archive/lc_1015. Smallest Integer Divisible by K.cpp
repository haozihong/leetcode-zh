// Math
// There is another solution in "solution" of this problem

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int r = 0, digi = 0;
        bool flag = true;
        do {
            flag = false;
            for (int i=0; i<=9; ++i)
                if ((K * i + r) % 10 == 1) {
                    r = (K * i + r) / 10;
                    flag = true;
                    ++digi;
                    break;
                }
        } while (flag && r);
        return flag ? digi : -1;
    }
};

