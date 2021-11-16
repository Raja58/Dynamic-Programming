// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        16 Nov 2021
//  @Detail  :        Valid Parenthesis String (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isValid(int idx, int open, string &str, vector<vector<int>> &dp)
    {
        if(idx == str.size())
        {
            if(open == 0)
                return true;
            return false;
        }
        
        if(dp[idx][open] != -1)
            return dp[idx][open];
        
        if(str[idx] == '(')
            return dp[idx][open] = isValid(idx + 1, open + 1, str, dp);
        
        if(str[idx] == ')' && open == 0)
            return dp[idx][open] = false;
        
        if(str[idx] == ')')
            return dp[idx][open] = isValid(idx + 1, open - 1, str, dp);

        for(int i : {-1, 0, 1})
            if(open + i >= 0 && isValid(idx + 1, open + i, str, dp))
                return dp[idx][open] = true;
        return dp[idx][open] = false;
    }
    
    bool checkValidString(string str) {
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, -1));
        return isValid(0, 0, str, dp);
    }
};
