class NumberContainers {
public:
    unordered_map<int, int> indexNum;
    unordered_map<int, set<int>> sortedSet;
    
    NumberContainers() {}
    
    void change(int index, int number) {
        
        if(indexNum.find(index) != indexNum.end()){
            int prevNumber = indexNum[index];
            sortedSet[prevNumber].erase(index);

            if(sortedSet[prevNumber].empty()) {
                sortedSet.erase(prevNumber);
            }
        }

        sortedSet[number].insert(index);
        indexNum[index] = number;
    }
    
    int find(int number) {
        auto it = sortedSet.find(number);
        if(it == sortedSet.end() || it->second.empty()) return -1;
        return *(it->second.begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */