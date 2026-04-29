class BrowserHistory {
public:
    int i;
    vector<string> arr;

    BrowserHistory(string homepage) {
        arr.push_back(homepage);
        i = 0;        
    }
    
    void visit(string url) {
        arr.erase(arr.begin()+i+1, arr.end());
        arr.push_back(url);
        i++;
    }
    
    string back(int steps) {
        
        (i - steps >= 0) ? i -= steps : i = 0;
        
        return arr[i];
    }
    
    string forward(int steps) {
        int n = arr.size();
        
        (i + steps < n) ? i += steps : i = n-1; 
        
        return arr[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */