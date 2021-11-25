// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Reducing Dishes (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMaxSat(int idx, int time, vector<int> &sat, vector<vector<int>> &dp)
    {
        if(idx == sat.size())
            return 0;
        if(dp[idx][time] != -1)
            return dp[idx][time];
        int pick = time * sat[idx] + getMaxSat(idx + 1, time + 1, sat, dp);
        int notPick = getMaxSat(idx + 1, time, sat, dp);
        return dp[idx][time] = max(pick, notPick);
    }
    
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        vector<vector<int>> dp(sat.size() + 1, vector<int>(sat.size() + 1, -1));
        return getMaxSat(0, 1, sat, dp);
    }
};
