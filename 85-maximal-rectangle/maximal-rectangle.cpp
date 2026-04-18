class Solution {
public:

    int findMax(vector<int> &arr){

        int n = arr.size();

        stack<int> st;

        vector<int> leftMinIdx(n);

        for(int i = 0; i<n; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            leftMinIdx[i] = (st.empty()) ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> rightMinIdx(n);

        for(int i = n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            rightMinIdx[i] = (st.empty()) ? n : st.top();

            st.push(i);
        }

        int res = 0;
        
        for(int i = 0; i<n; i++){
            res = max(res, arr[i]*(rightMinIdx[i] - leftMinIdx[i] - 1));
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> arr(n);

        int res = 0;

        for(int i = 0; i<m; i++){

            for(int j = 0; j<n; j++){
                if(matrix[i][j] == '1'){
                    arr[j] += 1;
                }else arr[j] = 0;    
            }

            res = max(res, findMax(arr));
        }

        return res;
    }
};