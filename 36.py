from collections import defaultdict
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        subboxes = collections.defaultdict(set)

        for row in range(9):
            for col in range(9):
                num = board[row][col]

                if num == ".":
                    continue
                
                if(num in rows[row] or num in cols[col] or num in subboxes[(row//3, col//3)]):
                    return False
                
                cols[col].add(num)
                rows[row].add(num)
                subboxes[(row//3, col//3)].add(num)
        return True