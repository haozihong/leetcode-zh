// Math, String

class Solution {
public:
    static constexpr int DS[]{1000'000'000, 1000'000, 1000, 100}, TWTY = 20;
    const string WK[4]{"Billion", "Million", "Thousand", "Hundred"};
    const string W20[20]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                      "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
                 WT[10]{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string numberToWords(int num) {
        if (num >= DS[2])
            for (int i=0; i<3; ++i)
                if (num >= DS[i])
                    return (numberToWords(num/DS[i]) + " " + WK[i] +
                            (num%DS[i] ? " " + numberToWords(num%DS[i]) : ""));
        string res = "";
        if (num >= DS[3]) res += " " + W20[num/DS[3]] + " " + WK[3], num %= DS[3];
        if (num >= TWTY) res += " " + WT[num/10], num %= 10;
        if (num > 0 || res == "") res += " " + W20[num];
        return res.substr(1);
    }
};