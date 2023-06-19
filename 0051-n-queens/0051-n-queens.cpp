class Solution {
public:
    bool check(vector<string>&board, int row, int col)
    {
        int i=row, j=col;

        while(i>=0 and j>=0){
            if(board[i][j]=='Q')return false;
            i--;j--;
        }

        i=row, j=col;

        while(j>=0){
            if(board[i][j]=='Q')return false;
            j--;
        }

        i=row, j=col;

        while(j>=0 and i<board.size()){
            if(board[i][j]=='Q')return false;
            i++;
            j--;
        }

        return true;
    }

    void func(vector<string>&board, int col, int n, vector<vector<string>>&ans)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++)
        {
            if(check(board, row, col))
            {
                board[row][col]='Q';
                func(board, col+1, n, ans);
                board[row][col]='.';
            }     
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);

        string s(n, '.');
        
        for(int i=0; i<n; i++)
            board[i] = s;

        func(board, 0, n, ans);

        return ans;
    }
};