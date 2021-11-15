// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        15 Nov 2021
//  @Detail  :        Stone Game V (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMaxStone(int start, int end, vector<int> &stone, vector<vector<int>> &dp)
    {
        if(start == end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int left = 0;
        int right = accumulate(stone.begin() + start, stone.begin() + end + 1, 0);
        int result = INT_MIN;
        
        for(int i = start; i < end; i++)
        {
            left += stone[i];
            right -= stone[i];
            
            if(left < right)
                result = max(result, left + getMaxStone(start, i, stone, dp));
            else if(left > right)
                result = max(result, right + getMaxStone(i + 1, end, stone, dp));
            else
            {
                int leftMax = left + getMaxStone(start, i, stone, dp);
                int rightMax = right + getMaxStone(i + 1, end, stone, dp);
                result = max({leftMax, rightMax, result});
            }
        }
        return dp[start][end] = result;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        vector<vector<int>> dp(stoneValue.size() + 1, vector<int>(stoneValue.size() + 1, -1));
        return getMaxStone(0, stoneValue.size() - 1, stoneValue, dp);
    }
};
