class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> qs;
        int n = queries.size();

        for(int i=0; i<n; i++){
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        vector<int> ans(n, -1);
        int i=0;

        for(auto q: qs){
            int query = q.first;
            int index = q.second;

        while(i<intervals.size() && intervals[i][0] <= query){
            int left = intervals[i][0];
            int right = intervals[i][1];

            int size = right-left+1;

            pq.push({size, right});
            i++;
        }

        while(!pq.empty() && pq.top().second < query){
            pq.pop();
        }
        if(!pq.empty()){
            ans[index] = pq.top().first;
        }
    }
    return ans;
    }
};