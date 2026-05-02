class TaskManager {
public:
    unordered_map<int, int> taskUser;
    unordered_map<int, int> taskPriority;
    multiset<pair<int, int>> maxHeap;

    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i<tasks.size(); i++){
            add(tasks[i][0], tasks[i][1], tasks[i][2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {

        taskUser[taskId] = userId;
        taskPriority[taskId] = priority;

        maxHeap.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {

        int currPriority = taskPriority[taskId];

        maxHeap.erase({currPriority, taskId});

        taskPriority[taskId] = newPriority;
        maxHeap.insert({newPriority, taskId});
        
    }
    
    void rmv(int taskId) {
        
        taskUser.erase(taskId);
        int currPriority = taskPriority[taskId];
        maxHeap.erase({currPriority, taskId});
        taskPriority.erase(taskId);

    }
    
    int execTop() {
        
        if(maxHeap.empty()) return -1;

        pair<int, int> mostPrior = *maxHeap.rbegin();
        maxHeap.erase(mostPrior);
        
        int priority = mostPrior.first;
        int taskId = mostPrior.second;

        int userId = taskUser[taskId];

        taskUser.erase(taskId);
        taskPriority.erase(taskId);

        return userId;
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */