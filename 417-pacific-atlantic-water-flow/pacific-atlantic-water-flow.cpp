class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c){
        int n = heights.size();
        int m = heights[0].size();

        visited[r][c]=true;

        for(int i=0; i<4; i++){
            int nr = r+directions[i][0];
            int nc = c+directions[i][1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc]){
                continue;
            }

        if(heights[nr][nc] >= heights[r][c]){
            dfs(heights, visited, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }
        for(int j=0; j<m; j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n-1, j);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
    return ans;
    }
};