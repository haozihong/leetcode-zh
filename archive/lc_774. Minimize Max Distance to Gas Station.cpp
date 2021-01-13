// Binary Search

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        sort(begin(stations), end(stations));
        vector<int> A;
        for (int i=0, n=stations.size(); i<n-1; ++i)
            A.push_back(stations[i+1] - stations[i]);
        double l = 0, r = *max_element(begin(A), end(A));
        while (abs(l - r) > 1e-6) {
            double m = (l + r) / 2;
            int t = 0;
            for (const auto& g : A) {
                t += ceil(g / m) - 1;
                if (t > K) break;
            }
            if (t <= K) r = m;
            else l = m;
        }
        return l;
    }
};