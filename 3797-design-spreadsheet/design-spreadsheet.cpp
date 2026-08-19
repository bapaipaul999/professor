class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.resize(rows + 1, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[row][col] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1); // remove '='

        int pos = formula.find('+');

        string a = formula.substr(0, pos);
        string b = formula.substr(pos + 1);

        return getCellValue(a) + getCellValue(b);
    }

    int getCellValue(string s) {
        // If it is a number
        if (isdigit(s[0])) {
            return stoi(s);
        }

        int col = s[0] - 'A';
        int row = stoi(s.substr(1));

        return sheet[row][col];
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */