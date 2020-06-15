class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> x, vector<int> y) { return x[1] < y[1]; });
        priority_queue<int> hp;
        int time = 0;
        for (auto &c : courses) {
            if (time + c[0] <= c[1]) {
                time += c[0];
                hp.push(c[0]);
            } else if (!hp.empty() && hp.top() > c[0] && time - hp.top() + c[0] <= c[1]) {
                time += c[0] - hp.top();
                hp.pop(); hp.push(c[0]);
            }
        }
        return hp.size();
    }
};