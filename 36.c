bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool Cols[9][9] = {0};
    bool Rows[9][9] = {0};
    bool Sub[9][9] = {0};

    for(int row = 0; row<9;row++){
        for(int col = 0; col<9;col++){
            char num = board[row][col];
            if(num=='.') continue;
            int x = (num -'0')%9;
            int subx = (row/3)*3 + col/3;
            if(Cols[col][x] || Rows[row][x] || Sub[subx][x]) return false;
            Cols[col][x] =1;
            Rows[row][x] = 1;
            Sub[subx][x] = 1;
        }
    }
    return true;
}