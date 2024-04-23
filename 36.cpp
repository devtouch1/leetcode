class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> subbox(9);
        vector<unordered_set<char>> cols(9);
        for(int row=0; row < 9; row++){
            unordered_set<char> lines;
            for(int col=0; col<9;col++){
                char num = board[row][col];
                
                //verifica se num é diferente de '.' e esta em algum dos sets. retorna falso
                if(num!='.'){
                    int loc = (row/3)*3 + col/3;
                    if(cols[col].find(num) != cols[col].end() || subbox[loc].find(num) != subbox[loc].end() || lines.find(num) != lines.end()) return false;

                //insere em cada set o num
                lines.insert(num);
                cols[col].insert(num);
                subbox[loc].insert(num);

                }
                
            }
        }
        return true;
    }
};