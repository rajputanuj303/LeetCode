class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> stt(bank.begin(), bank.end());
        if(!stt.count(endGene)) return -1; // early check

        queue<pair<string, int>> que;

        vector<char> chars = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;


        que.push({startGene, 0});
        visited.insert(startGene);

        while(!que.empty()){

            string curr = que.front().first;
            int steps = que.front().second;
            que.pop();

            if(curr == endGene) return steps;

            for(char c : chars){
                for(int i = 0; i<curr.size(); i++){
                    if(curr[i] == c) continue;

                    char temp = curr[i]; // store
                    curr[i] = c;

                    if(!visited.count(curr) && stt.count(curr)){
                        que.push({curr, steps+1});
                        visited.insert(curr); // mark visited
                    }

                    curr[i] = temp; // restore
                }
            }            

        }

        return -1;
    }
};