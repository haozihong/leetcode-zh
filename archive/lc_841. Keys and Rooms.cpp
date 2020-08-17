// Graph, DFS?

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> open(n, false);
        open[0] = true;
        deque<int> que{0};
        while (!que.empty()) {
            for (auto &j : rooms[que.front()])
                if (!open[j]) {
                    open[j] = true;
                    que.push_back(j);
                }
            que.pop_front();
        }
        return find(begin(open), end(open), false) == end(open);
    }
};