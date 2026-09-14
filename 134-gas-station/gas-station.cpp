class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int total = 0;
      int tank = 0;
      int start = 0;

      for(int i=0; i<gas.size(); i++){
        int gain = gas[i] - cost[i];
        tank += gain;
        total += gain;

        if(tank < 0){
            tank = 0;
            start = i+1;
        }
      }
      return (total >= 0) ? start : -1;
    }
};