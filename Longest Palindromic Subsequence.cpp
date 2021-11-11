// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        11 Nov 2021
//  @Detail  :        Longest Palindromic Subsequence (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getLongPali(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if(i == -1 || j == -1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(str1[i] == str2[j])
            return dp[i][j] = 1 + getLongPali(i - 1, j - 1, str1, str2, dp);
        return dp[i][j] = max(getLongPali(i - 1, j, str1, str2, dp), getLongPali(i, j - 1, str1, str2, dp));
    }
    
    int longestPalindromeSubseq(string str1) {
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, -1));
        return getLongPali(str1.size() - 1, str2.size() - 1, str1, str2, dp);
    }
};
