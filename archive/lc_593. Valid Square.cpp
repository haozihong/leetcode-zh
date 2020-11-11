// Math

class Solution1 {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        valarray<double> xs{0. + p1[0], 0. + p2[0], 0. + p3[0], 0. + p4[0]},
                         ys{0. + p1[1], 0. + p2[1], 0. + p3[1], 0. + p4[1]};
        double cen_x = xs.sum() / 4.0, cen_y = ys.sum() / 4.0;
        for (int i=0; i<4; ++i)
            if (abs(xs[i]-cen_x) <= 0.0001 && abs(ys[i]-cen_y) <= 0.0001) return false;
        auto angs = atan2(ys - cen_y, xs - cen_x);
        int ii[]{0,1,2,3};
        sort(ii, end(ii), [&angs](auto &x, auto &y){ return angs[x] < angs[y]; });
        int dx = xs[ii[0]] - xs[ii[3]], dy = ys[ii[0]] - ys[ii[3]];
        if (xs[ii[1]] - xs[ii[0]] == -dy && ys[ii[1]] - ys[ii[0]] == dx &&
            xs[ii[2]] - xs[ii[1]] == -dx && ys[ii[2]] - ys[ii[1]] == -dy &&
            xs[ii[3]] - xs[ii[2]] == dy && ys[ii[3]] - ys[ii[2]] == -dx)
            return true;
        else return false;
    }
};

class Solution {
public:
    inline int dist_sq(vector<int> &p1, vector<int> &p2) {
        auto x = p1[0] - p2[0], y = p1[1] - p2[1];
        return x*x + y*y;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        array<int, 6> ds{
            dist_sq(p1, p2),
            dist_sq(p1, p3),
            dist_sq(p1, p4),
            dist_sq(p2, p3),
            dist_sq(p2, p4),
            dist_sq(p3, p4)
        };
        sort(begin(ds), end(ds));
        return (ds[0] > 0 &&
                ds[0] == ds[3] &&
                ds[4] == ds[5]);
    }
};