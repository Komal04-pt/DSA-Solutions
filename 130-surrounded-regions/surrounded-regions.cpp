class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                if(board[i][j]=='O'){
                    board[i][j] = '#';
                    q.push({i,j});
                    }
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for(int i=0; i<4; i++){
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(r>=0 && r<n && c>=0 && c<m && board[r][c]=='O'){
                    board[r][c]='#';
                    q.push({r,c});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};