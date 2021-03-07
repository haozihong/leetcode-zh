// Hash Table, Design

class MyHashMap {
    static constexpr int SZ = 10007;
    array<list<pair<int, int>>, SZ> tb;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for (auto &[k, v] : tb[key%SZ])
            if (k == key) { v = value; return; }
        tb[key%SZ].emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (auto &[k, v] : tb[key%SZ])
            if (k == key) return v;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for (auto it=tb[key%SZ].begin(), ed=tb[key%SZ].end(); it!=ed; ++it)
            if (it->first == key) { tb[key%SZ].erase(it); return; }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */