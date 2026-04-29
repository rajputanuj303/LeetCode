class MyHashSet {
public:
    vector<bool> v;

    MyHashSet() {
        v = vector<bool>(1000001, false); 
    }

    void add(int key) {
        v[key] = true; 
    }

    void remove(int key) {
        v[key] = false; 
    }

    bool contains(int key) {
        return v[key]; 
    }
};