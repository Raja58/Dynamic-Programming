// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Nov 2021
//  @Detail  :        Unique Binary Search Trees (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getSoul(int n, vector<int> &dp)
    {
        if(n <= 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
      
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += getSoul(i, dp) * getSoul(n - 1 - i, dp);
        return dp[n] = cnt;
    }
    
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return getSoul(n, dp);
    }
};
