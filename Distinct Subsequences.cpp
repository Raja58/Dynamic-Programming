// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        11 Nov 2021
//  @Detail  :        Distinct Subsequences (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getDistSub(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = getDistSub(i + 1, j + 1, s, t, dp) + getDistSub(i + 1, j, s, t, dp);
        return dp[i][j] = getDistSub(i + 1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return getDistSub(0, 0, s, t, dp);
    }
};
