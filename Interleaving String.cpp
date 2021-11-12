// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Nov 2021
//  @Detail  :        Interleaving String (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isInter(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp)
    {
        int k = i + j;
        if(k == s3.size())
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s3[k])
            if(isInter(i + 1, j, s1, s2, s3, dp))
                return dp[i][j] = true;
        if(s2[j] == s3[k])
            if(isInter(i, j + 1, s1, s2, s3, dp))
                return dp[i][j] = true;
        return dp[i][j] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return isInter(0, 0, s1, s2, s3, dp);
    }
};
