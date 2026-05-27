class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char c : tasks){
            freq[c-'A']++;
        }

        priority_queue<int> que;

        for(int f : freq){
            if(f) que.push(f);
        }

        int res = 0;

        while(!que.empty()){

            int cycle = n+1;
            vector<int> temp;

            while(cycle > 0 && !que.empty()){
                int val = que.top();
                que.pop();
                res++;

                if(val - 1 > 0) temp.push_back(val-1);
                cycle--;
            }

            for(int i : temp) que.push(i);

            if(!que.empty()) res += cycle;

        }
        return res;
    }
};