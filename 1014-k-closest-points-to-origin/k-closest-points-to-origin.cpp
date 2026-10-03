class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxh;

        for(auto point: points){
            int x = point[0];
            int y = point[1];

            int dist = x*x + y*y;

            maxh.push({dist, point});
            if(maxh.size() > k){
                maxh.pop();
            }
        }

        vector<vector<int>> ans;
        while(!maxh.empty()){
            ans.push_back({maxh.top().second});
            maxh.pop();
        }
        return ans;
    }
};