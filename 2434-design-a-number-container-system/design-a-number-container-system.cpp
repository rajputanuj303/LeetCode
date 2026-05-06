class NumberContainers {
public:
    unordered_map<int, int> indexNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    NumberContainers() {}

    void change(int index, int number) {
        indexNum[index] = number;
        mp[number].push(index);  // no deletion
    }

    int find(int number) {
        if(mp.find(number) == mp.end()) return -1;

        auto &pq = mp[number];

        while(!pq.empty()) {
            int idx = pq.top();
            if(indexNum[idx] == number) {
                return idx;  // valid
            }
            pq.pop(); // lazy delete
        }

        return -1;
    }
};