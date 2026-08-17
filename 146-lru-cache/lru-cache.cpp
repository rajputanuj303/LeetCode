class LRUCache {
public:

    int counter;
    int size;
    unordered_map<int, int> keyValue;
    set<pair<int, int>> stt;
    unordered_map<int, int> counterMap;

    LRUCache(int capacity) {
        size = capacity;
        counter = 0;
    }
    
    int get(int key) {
        if (counterMap.count(key) == 0) return -1;

        int prevCntr = counterMap[key];

        // Remove old position
        stt.erase({prevCntr, key});

        // Mark as recently used
        counter++;
        stt.insert({counter, key});
        counterMap[key] = counter;

        return keyValue[key];
    }
    
    void put(int key, int value) {

        counter++;

        // If key already exists, remove its old position
        if (counterMap.count(key)) {
            int prevCntr = counterMap[key];
            stt.erase({prevCntr, key});
        }

        // Update value and mark as recently used
        counter++;
        keyValue[key] = value;
        counterMap[key] = counter;
        stt.insert({counter, key});

        // Evict least recently used
        if (stt.size() > size) {
            pair<int, int> p = *stt.begin();

            int oldKey = p.second;

            stt.erase(stt.begin());
            keyValue.erase(oldKey);
            counterMap.erase(oldKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */