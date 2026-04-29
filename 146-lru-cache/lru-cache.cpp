class LRUCache {
public:
    list<int> dll; // front is latest and back is oldest

    // {key, {value, node-iterator}}
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;

        dll.erase(cache[key].second);
        dll.push_front(key);
        cache[key].second = dll.begin();
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key].first = value;
            dll.erase(cache[key].second);
            dll.push_front(key);
            cache[key].second = dll.begin();
        }else{
            dll.push_front(key);
            cache[key] = {value, dll.begin()};
            cap--;
        }

        if(cap < 0){
            int keyDel = dll.back();
            cache.erase(keyDel);

            dll.pop_back();

            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */