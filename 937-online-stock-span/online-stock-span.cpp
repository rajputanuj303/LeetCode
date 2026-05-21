class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i;
    StockSpanner() {
        i = -1;
        st.push({-1, 1e9+7});
    }
    
    int next(int price) {

        i++;
        
        while(!st.empty()){
            auto [idx, val] = st.top();
            if(val <= price) st.pop();
            else break;
        }

        int idx = st.top().first;
        st.push({i, price});

        return i - idx;       
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */