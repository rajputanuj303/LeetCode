class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        stack<pair<int,int>> right_stack;
        stack<pair<int,int>> left_stack;

        right_stack.push({INT_MIN, n});
        left_stack.push({INT_MIN, -1});

        vector<int> leftMinIdx(n);
        vector<int> rightMinIdx(n);

        for(int i = 0; i<n; i++){

            int leftHeight = heights[i];
            int rightHeight = heights[n-i-1];

            while(left_stack.top().first >= leftHeight) left_stack.pop();
            while(right_stack.top().first >= rightHeight) right_stack.pop();

            leftMinIdx[i] = left_stack.top().second;
            rightMinIdx[n-i-1] = right_stack.top().second;

            left_stack.push({heights[i], i});
            right_stack.push({heights[n-i-1], n-i-1});
        }


        int maxSize = 0;

        for(int i = 0; i<n; i++){
            maxSize = max(maxSize, heights[i]*(rightMinIdx[i] - leftMinIdx[i] - 1));
        }

        return maxSize;
    }
};