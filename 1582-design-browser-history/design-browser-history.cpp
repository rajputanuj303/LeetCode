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
        if(steps > i){
            i = 0;
        }else i -= steps;
        
        return arr[i];
    }
    
    string forward(int steps) {
        
        if(i + steps < arr.size()){
            i += steps;
        }else{
            i = arr.size()-1;
        }
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