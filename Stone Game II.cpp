// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        15 Nov 2021
//  @Detail  :        Stone Game II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMaxStone(int idx, int m, vector<int> &piles, vector<vector<int>> &dp)
    {
        if(idx == piles.size())
            return 0;
        
        if(dp[idx][m] != -1)
            return dp[idx][m];
        
        int result = 0;
        for(int x = 1; x <= 2 * m; x ++)
        {
            if(idx + x - 1 >= piles.size())
                break;
            
            int poten = accumulate(piles.begin() + idx, piles.begin() + idx + x, 0);
            
            int newM = max(x, m), mini = INT_MAX;
            for(int y = 1; y <= 2 * newM; y++)
            {
                if(idx + x + y - 1 >= piles.size())
                    break;
                
                int temp = getMaxStone(idx + x + y, max(y, newM), piles, dp);
                
                if(temp < mini)
                    mini = temp;
            }
            
            if(mini != INT_MAX)
                poten += mini;
            
            if(poten > result)
                result = poten;
        }
        return dp[idx][m] = result;
    }
    
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(2 * piles.size() + 1, -1));
        return getMaxStone(0, 1, piles, dp);
    }
};
