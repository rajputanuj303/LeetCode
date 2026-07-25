class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2){
        if(v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        

        sort(courses.begin(), courses.end(), cmp);

        priority_queue<int> pq;

        int timeConsumed = 0;

        for(const vector<int> &v : courses){

            if(timeConsumed + v[0] <= v[1]){
                timeConsumed += v[0];
                pq.push(v[0]);
            }else if(!pq.empty() && pq.top() > v[0]){
                timeConsumed -= pq.top();
                pq.pop();
                timeConsumed += v[0];
                pq.push(v[0]);
            }
        }

        return pq.size();
    }
};