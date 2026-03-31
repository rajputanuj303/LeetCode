class Solution {
public: 

    void DFS(int u, vector<vector<int>> &rooms, vector<bool> &visited){
        
        visited[u] = true;

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
        
        for(bool b : visited){
            if(!b) return false;
        }
        return true;
    }
};