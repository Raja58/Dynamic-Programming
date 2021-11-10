// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        10 Nov 2021
//  @Detail  :        Minimum Cost For Tickets (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMinCost(int idx, int validTill, vector<int>& days, vector<int>& costs, vector<vector<int>> &dp)
    {
        if(idx == days.size())
            return 0;
        if(dp[idx][validTill] != -1)
            return dp[idx][validTill];
        if(validTill >= days[idx])
            return getMinCost(idx + 1, validTill, days, costs, dp);
        int result = INT_MAX;
        const vector<int> pass{1, 7, 30};
        for(int i = 0; i < 3; i++)
        {
            int temp = costs[i] + getMinCost(idx + 1, days[idx] + pass[i] - 1, days, costs, dp);
            if( result > temp)
                result = temp;
        }
        return dp[idx][validTill] = result;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size() + 1, vector<int>(400, -1));
        return getMinCost(0, 0, days, costs, dp);
    }
};
