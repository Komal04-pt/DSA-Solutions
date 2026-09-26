class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, time = 0;

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty() && fresh>0){
            int length = q.size();
            for(int i=0; i<length; i++){
                auto curr = q.front();
                q.pop();
            int row = curr.first;
            int col = curr.second;

            for(int i=0; i<4; i++){
                int r = row+directions[i][0];
                int c = col+directions[i][1];

                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1){
                    grid[r][c] = 2;
                    q.push({r,c});
                    fresh--;
                    }
                }
            }
            time++;
        }
        return fresh==0?time:-1;
    }
};