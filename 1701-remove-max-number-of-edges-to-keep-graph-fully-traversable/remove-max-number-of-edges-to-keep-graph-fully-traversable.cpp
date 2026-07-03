class Solution {
public:
    vector<int> parentAlice;
    vector<int> parentBob;

    int findAlice(int a){
        if(parentAlice[a] == a) return a;
        return parentAlice[a] = findAlice(parentAlice[a]);
    }

    int findBob(int a){
        if(parentBob[a] == a) return a;
        return parentBob[a] = findBob(parentBob[a]);
    }
    

    void UnionAlice(int u, int v){
        
        int parentAliceU = findAlice(u);
        int parentAliceV = findAlice(v);

        if(parentAliceU != parentAliceV){
            parentAlice[parentAliceV] = parentAliceU;
        }
    }

    void UnionBob(int u, int v){

        int parentBobU = findBob(u);
        int parentBobV = findBob(v);

        if(parentBobU != parentBobV){
            parentBob[parentBobV] = parentBobU;
        }
    }


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        for(int i = 0; i<=n; i++){
            parentAlice.push_back(i);
            parentBob.push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int> &e1, const vector<int> &e2){
            return e1[0] > e2[0];
        });

        int countRemoves = 0;

        for(vector<int> &edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3){
                bool used = false;

                if(findAlice(u) != findAlice(v)){
                    UnionAlice(u, v);
                    used = true;
                }

                if(findBob(u) != findBob(v)){
                    UnionBob(u, v);
                    used = true;
                }

                if(!used) countRemoves++;

            }else if(type == 1){
                int parentAliceU = findAlice(u);
                int parentAliceV = findAlice(v);

                if(parentAliceU == parentAliceV) countRemoves++;
                else UnionAlice(u, v);
            
            }else if(type == 2){
                int parentBobU = findBob(u);
                int parentBobV = findBob(v);

                if(parentBobU == parentBobV) countRemoves++;
                else UnionBob(u, v);
            }
        }

        unordered_set<int> aliceCount, bobCount;

        for(int i = 1; i<=n; i++){
            aliceCount.insert(findAlice(i));
            bobCount.insert(findBob(i));
        }


        if(aliceCount.size() == 1 && bobCount.size() == 1) return countRemoves;
        return -1;
    }
};