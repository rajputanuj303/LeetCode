class Solution {
public:
    int nthUglyNumber(int n) {

        if(n == 1) return 1;


        n--;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_map<long long, bool> visited;

        pq.push(2);
        pq.push(3);
        pq.push(5);

        while(--n){

            long long curr = pq.top(); pq.pop();            

            long long m1 = curr*2;
            long long m2 = curr*3;
            long long m3 = curr*5;

            if(visited.find(m1) == visited.end()){
                visited[m1] = true;
                pq.push(m1);
            }
            if(visited.find(m2) == visited.end()){
                visited[m2] = true;
                pq.push(m2);
            }

            if(visited.find(m3) == visited.end()){
                visited[m3] = true;
                pq.push(m3);
            }

        }
        return pq.top();
    }
};