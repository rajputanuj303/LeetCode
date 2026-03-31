class Solution {
public: 

    int count = 0;

    void DFS(int u, vector<vector<int>> &rooms, vector<bool> &visited){
        
        visited[u] = true;
        count++;

        for(int v : rooms[u]){
            if(!visited[v]){
                DFS(v, rooms, visited);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        DFS(0, rooms, visited);

        return count == n;
    }
};