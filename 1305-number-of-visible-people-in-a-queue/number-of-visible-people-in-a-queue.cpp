class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();

        vector<int> res(n);

        for(int i = n-1; i>=0; i--){
            int cnt = 0;
            while(!st.empty()){
                cnt++;
                if(st.top() < heights[i]){
                    st.pop();
                }else break;
            }

            res[i] = cnt;
            st.push(heights[i]);

        }

        return res;
    }
};