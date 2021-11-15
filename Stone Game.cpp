// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        15 Nov 2021
//  @Detail  :        Stone Game (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMaxStone(int start, int end, vector<int> &piles, vector<vector<int>> &dp)
    {
        if(start + 1 == end)
            return max(piles[start], piles[end]);
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int left = piles[start] + min(getMaxStone(start + 1, end - 1, piles, dp), getMaxStone(start + 2, end, piles, dp));
        int right = piles[end] + min(getMaxStone(start + 1, end - 1, piles, dp), getMaxStone(start, end - 2, piles, dp));
        return dp[start][end] = max(left, right);
    }
    
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, -1));
        int result = getMaxStone(0, piles.size() - 1, piles, dp);
        return result > accumulate(piles.begin(), piles.end(), 0) - result;
    }
};
