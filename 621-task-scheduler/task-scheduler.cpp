class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task: tasks){
            freq[task-'A']++;
        }

        priority_queue<int> pq;
        for(int count: freq){
            if(count > 0){
                pq.push(count);
            }
        }

        queue<pair<int,int>> coolDown;
        int time = 0;

        while(!pq.empty() || !coolDown.empty()){
            time++;

            while(!coolDown.empty() && coolDown.front().second <= time){
                pq.push(coolDown.front().first);
                coolDown.pop();
            }
            if(!pq.empty()){
                int count = pq.top();
                pq.pop();

                count--;

            if(count > 0){
                coolDown.push({count, time+n+1});
                }
            }
        }
        return time;
    }
};