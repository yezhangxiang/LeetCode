class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, start = 0, min = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            tank += (gas[i]-cost[i]);
            if (tank < min )
            {
                min = tank;
                start = i+1;
            }
        }
        if (tank < 0)
        {
            start = -1;
        }
        return start;
    }
};

