// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Nov 2021
//  @Detail  :        Triangle (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMin(int row, int idx, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(row == triangle.size() - 1)
            return triangle[row][idx];
        if(dp[row][idx] != INT_MAX)
            return dp[row][idx];
        return dp[row][idx] = triangle[row][idx] + min(getMin(row + 1, idx, triangle, dp), getMin(row + 1, idx + 1, triangle, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size() + 1, vector<int>(triangle.size() + 1, INT_MAX));
        return getMin(0, 0, triangle, dp);
    }
};
