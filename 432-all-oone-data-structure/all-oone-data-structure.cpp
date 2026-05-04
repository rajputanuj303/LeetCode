class AllOne {
public:
    unordered_map<string, int> keyFreq;
    set<pair<int, string>> maxSet;

    AllOne() {}
    
    void inc(string key) {

        int freq = keyFreq[key];

        if(freq > 0) maxSet.erase({freq, key});
        
        keyFreq[key] = freq+1;
        maxSet.insert({freq+1, key});
    }
    
    void dec(string key) {

        int freq = keyFreq[key];
        
        if(maxSet.count({freq, key})) maxSet.erase({freq, key});

        if(freq-1 == 0){
            keyFreq.erase(key);
            return;
        }
        keyFreq[key] = freq-1;
        maxSet.insert({freq-1, key});
    }
    
    string getMaxKey() {
        if(maxSet.empty()) return "";

        pair<int, string> top = *maxSet.rbegin();
        return top.second;
    }
    
    string getMinKey() {
        if(maxSet.empty()) return "";

        pair<int, string> top = *maxSet.begin();
        return top.second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */