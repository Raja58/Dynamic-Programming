// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Nov 2021
//  @Detail  :        Ones and Zeroes (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<int> getCnt(string &str)
    {
        int zero = 0, one = 0;
        for(char &c : str)
            if(c == '0')
                zero++;
            else
                one++;
        return vector<int>{zero, one};
    }
    
    int getSoul(int idx, int m, int n, vector<vector<int>> &input, int dp[601][101][101])
    {
        if(idx == input.size())
            return 0;
        if(dp[idx][m][n] != -1)
            return dp[idx][m][n];
        int pick = INT_MIN, notPick = INT_MIN;
        if(m - input[idx][0] >= 0 && n - input[idx][1] >= 0)
            pick = 1 + getSoul(idx + 1, m - input[idx][0], n - input[idx][1], input, dp);
        notPick = getSoul(idx + 1, m, n, input, dp);
        return dp[idx][m][n] = max(pick, notPick);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> input(strs.size());
        for(int i = 0; i < strs.size(); i++)
            input[i] = getCnt(strs[i]);
        int dp[601][101][101];
        memset(dp, -1, sizeof(dp));
        return getSoul(0, m, n, input, dp);
    }
};
