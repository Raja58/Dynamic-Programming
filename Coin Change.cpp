// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        10 Nov 2021
//  @Detail  :        Coin Change (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    long long getMin(int idx, int cur, int sum, vector<int> &coins, vector<vector<long long>> &dp)
    {
        if(cur == sum)
            return 0;
        if(idx == coins.size())
            return INT_MAX;
        if(dp[idx][cur] != -1)
            return dp[idx][cur];
        long long pick = INT_MAX, notPick = INT_MAX;
        if((long long)cur + coins[idx] <= sum)
            pick = getMin(idx, cur + coins[idx], sum, coins, dp);
        if(pick != INT_MAX)
            pick += 1;
        notPick = getMin(idx + 1, cur, sum, coins, dp);
        return dp[idx][cur] = min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long long>> dp(coins.size() + 1, vector<long long>(amount + 1, -1));
        int result = getMin(0, 0, amount, coins, dp);
        return result == INT_MAX ? -1 : result;
    }
};
