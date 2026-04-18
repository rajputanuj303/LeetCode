class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        stack<int> st;

        vector<int> leftMinIdx(n);
        // filling left Minimum Indexes
        for(int i = 0; i<n; i++){            
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            leftMinIdx[i] = (st.empty()) ? -1 : st.top();    
            st.push(i);        
        }

        while(!st.empty()) st.pop();

        vector<int> rightMinIdx(n);
        // filling right Minimum Indexes
        for(int i = n-1; i >= 0; i--){            
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            rightMinIdx[i] = (st.empty()) ? n : st.top();   
            st.push(i);         
        }

        int maxSize = 0;

        for(int i = 0; i<n; i++){
            maxSize = max(maxSize, heights[i]*(rightMinIdx[i] - leftMinIdx[i] - 1));
        }

        return maxSize;
    }
};