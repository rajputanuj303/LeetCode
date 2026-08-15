class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<int> res(n, 0);

        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temp[st.top()] <= temp[i]) st.pop();
            res[i] = (st.empty()) ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
    }
};