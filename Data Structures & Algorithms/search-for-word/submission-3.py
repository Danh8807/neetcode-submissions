class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        count = [[False] * len(board[0]) for _ in board]
        self.status = False
        def dfs(row, col, i):
            if( i == len(word)):
                self.status = True
                return
            if row < 0 or col < 0 or row >= len(board) or col >= len(board[0]):
                return
            if board[row][col] != word[i]:
                return
            if count[row][col]:
                return
            count[row][col] = True
            dfs(row-1, col, i + 1);
            dfs(row +1, col, i + 1);
            dfs(row, col - 1, i + 1);
            dfs(row, col + 1, i + 1);
            count[row][col] = False
        for row in range(len(board)): 
            for col in range(len(board[0])): 
                dfs(row,col,0)
                if self.status == True:
                    return True
        return False
              