class Spreadsheet {
public:
    vector<vector<int>> Sheet;
    Spreadsheet(int rows) {
        Sheet.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1)) - 1;

        Sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1))-1;

        Sheet[row][col] = 0;
    }

    int SheetFinder(string cell){
        if(isdigit(cell[0])){
            return stoi(cell);
        }

        int col = cell[0]-'A';
        int row = stoi(cell.substr(1)) - 1;
        return Sheet[row][col];
    }
    
    int getValue(string formula) {
        
        int plusIdx = formula.find('+');

        string x = formula.substr(1, plusIdx);
        string y = formula.substr(plusIdx+1);

        return SheetFinder(x) + SheetFinder(y);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */