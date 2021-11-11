// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        11 Nov 2021
//  @Detail  :        Wildcard Matching (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isValid(int sIdx, int pIdx, string &str, string &pat, vector<vector<int>> &dp)
    {
//         out of bound conditions
        if(sIdx == str.size() && pIdx == pat.size())
            return true;
        
        if(pIdx == pat.size())
            return false;
        
        if(sIdx == str.size())
            if(pat[pIdx] == '*')
                return isValid(sIdx, pIdx + 1, str, pat, dp);
            else
                return false;
        
        if(dp[sIdx][pIdx] != -1)
            return dp[sIdx][pIdx];
//         if chars are same
        if(str[sIdx] == pat[pIdx])
            return dp[sIdx][pIdx] = isValid(sIdx + 1, pIdx + 1, str, pat, dp);
//         special chars
        if(pat[pIdx] == '?')
            return dp[sIdx][pIdx] = isValid(sIdx + 1, pIdx + 1, str, pat, dp);
        else if(pat[pIdx] == '*')
            for(int i = sIdx; i <= str.size(); i++)
                if(isValid(i, pIdx + 1, str, pat, dp))
                    return dp[sIdx][pIdx] = true;
        return dp[sIdx][pIdx] = false;
    }
    
    bool isMatch(string str, string pat) {
        vector<vector<int>> dp(str.size() + 1, vector<int>(pat.size() + 1, -1));
        return isValid(0, 0, str, pat, dp);
    }
};
