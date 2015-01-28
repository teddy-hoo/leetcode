/**
 * Greedy algorithm
 * Time: O(n)
 * Space: O(1)
 * Author: Teddy
 * Date: 28-1-2015
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int len = gas.size();
        if(len <= 0){
            return -1;
        }
        
        int totalGas = 0;
        
        int startStation;
        int leftGas = 0;
        
        for(int i = 0; i < len; i++){
            totalGas += gas[i] - cost[i];
            if(leftGas <= 0){
                startStation = i;
                leftGas = gas[i] - cost[i];
            }
            else{
                leftGas += gas[i] - cost[i];
            }
        }
        
        if(totalGas >= 0){
            return startStation;
        }
        
        return -1;
    }
};