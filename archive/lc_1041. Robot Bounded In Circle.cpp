// Math

class Solution {
public:
    const array<array<int, 2>, 4> DIR{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, di = 0;
        for (auto c : instructions) {
            switch (c) {
                case 'G':
                    x += DIR[di][0]; y += DIR[di][1];
                    break;
                default:
                    di = (di + (c == 'R' ? 1 : 3)) % 4;
            }
        }
        return (di != 0 || (x == 0 && y == 0));
    }
};