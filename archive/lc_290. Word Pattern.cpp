// String, Hash Table

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> ws;
        istringstream s(str);
        string tmp;
        while (s >> tmp) ws.push_back(tmp);
        for (auto &s : ws) printf("%s ", s.c_str()); cout << endl;
        if (ws.size() != pattern.length()) return false;
        
        unordered_map<char, string> map;
        unordered_set<string> seen;
        for (int i=0, l=ws.size(); i<l; ++i) {
            if (map.count(pattern[i])) {
                if (map[pattern[i]] != ws[i]) return false;
            } else {
                if (seen.count(ws[i])) return false;
                map[pattern[i]] = ws[i];
                seen.insert(ws[i]);
            }
        }
        return true;
    }
};