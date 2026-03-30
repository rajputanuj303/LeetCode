class EventManager {
public:

    unordered_map<int, int> mpp;

    struct cmp {
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    EventManager(vector<vector<int>>& events) {
        for(vector<int> v : events){
            mpp[v[0]] = v[1];
            pq.push({v[1], v[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mpp[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }
    
    int pollHighest() {

        while(!pq.empty()){
            auto [pr, id] = pq.top();
            pq.pop();

            if(mpp.count(id) && mpp[id] == pr){
                mpp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */