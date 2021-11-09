// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Nov 2021
//  @Detail  :        Word Break (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool getSoul(int idx, string &s, unordered_set<string> &word, vector<int> &dp)
    {
        if(idx == s.size())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        for(int i = idx; i < s.size(); i++)
        {
            string x = s.substr(idx, i - idx + 1);
            if(word.find(x) != word.end())
                if(getSoul(i + 1, s, word, dp))
                    return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word;
        for(auto &x : wordDict)
            word.insert(x);
        vector<int> dp(s.size(), -1);
        return getSoul(0, s, word, dp);
    }
};
