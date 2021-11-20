// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Nov 2021
//  @Detail  :        Can I Win (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool getWin(int mask, int curSum, int &x, int &desiredTotal, vector<int> &dp)
    {
        if(dp[mask] != -1)
            return dp[mask];
        
        int curPlayer = __builtin_popcount(mask) & 1 ? 1 : 0;
        
        for(int i = 1; i <= x; i++)
        {
            if(mask & (1 << i))
                continue;
            if(curSum + i >= desiredTotal)
                return dp[mask] = curPlayer;
            else if(getWin(mask | (1 << i), curSum + i, x, desiredTotal, dp) == curPlayer)
                return dp[mask] = curPlayer;
        }
        return dp[mask] = !curPlayer;
    }
    
    bool canIWin(int x, int desiredTotal) {
        if((x * (x + 1)) / 2 < desiredTotal)
            return false;
        vector<int> dp((1 << (x + 1)) + 1, -1);
        return getWin(0, 0, x, desiredTotal, dp) == 0;
    }
};
