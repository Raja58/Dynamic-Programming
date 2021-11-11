// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        11 Nov 2021
//  @Detail  :        Regular Expression Matching (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isValid(int sIdx, int pIdx, string &str, string &pat, vector<vector<int>> &dp)
    {
//         base cases
        if(sIdx == -1 && pIdx == -1)
            return true;
        if(pIdx == -1)
            return false;
        if(sIdx == -1)
        {
            if(pat[pIdx] == '*')
                return isValid(sIdx, pIdx - 2, str, pat, dp);
            else
                return false;
        }
        
        if(dp[sIdx][pIdx] != -1)
           return dp[sIdx][pIdx];
            
//         exact matches
        if(str[sIdx] == pat[pIdx])
            return dp[sIdx][pIdx] = isValid(sIdx - 1, pIdx - 1, str, pat, dp);
//         special characters
        if(pat[pIdx] == '.')
            return dp[sIdx][pIdx] = isValid(sIdx - 1, pIdx - 1, str, pat, dp);
        else if(pat[pIdx] == '*')
        {
            if(pat[pIdx - 1] == '.')
            {
                for(int i = sIdx; i >= -1; i--)
                    if(isValid(i, pIdx - 2, str, pat, dp))
                        return dp[sIdx][pIdx] = true;
            }
            else
            {
                 if(isValid(sIdx, pIdx - 2, str, pat, dp))
                        return dp[sIdx][pIdx] = true;
                for(int i = sIdx; i >= 0; i--)
                {
                    string temp = str.substr(i, sIdx - i + 1);
                    char x = pat[pIdx - 1];
                    if(all_of(temp.begin(), temp.end(), [x](char c) { return c == x;}))
                    {
                        if(isValid(i - 1, pIdx - 2, str, pat, dp))
                            return dp[sIdx][pIdx] = true;
                    }
                    else
                        return dp[sIdx][pIdx] = false;
                }
            }
        }
        return dp[sIdx][pIdx] = false;
    }
    
    bool isMatch(string str, string pat){
        vector<vector<int>> dp(str.size() + 1, vector<int>(pat.size() + 1, -1));
        return isValid(str.size() - 1, pat.size() - 1, str, pat, dp);
    }
};
