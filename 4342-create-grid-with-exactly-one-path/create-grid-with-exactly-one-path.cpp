class Solution {
public:
    vector<string> createGrid(int m, int n) {

        string topRow(n, '.');// top row of colm 
        string remaining = string(n - 1, '#') + '.';

        vector<string> result;
        result.push_back(topRow);

        for (int i = 1; i < m; i++) { // m = no  of rows
            result.push_back(remaining);
        }

        return result;
    }
};
