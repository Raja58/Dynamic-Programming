// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        14 Nov 2021
//  @Detail  :        Integer Break (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMaxProd(int num, int cur, int &n, vector<vector<int>> &dp)
    {
        if(cur == n)
            return 1;
        if(num == n || cur + num > n)
            return 0;
        if(dp[num][cur] != -1)
            return dp[num][cur];
        int pick = num * getMaxProd(num, cur + num, n, dp);
        int notPick = getMaxProd(num + 1, cur, n, dp);
        return dp[num][cur] = max(pick, notPick);
    }
    
    int integerBreak(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return getMaxProd(1, 0, n, dp);
    }
};
