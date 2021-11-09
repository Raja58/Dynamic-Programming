// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Nov 2021
//  @Detail  :        Word Break II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<string> getAll(int idx, string str, 
            unordered_set<string> &dict, unordered_map<int, vector<string>> &dp)
    {
        if(idx == str.size())
            return {""};
        if(dp.find(idx) != dp.end())
            return dp[idx];
        vector<string> allCombi;
        for(int i = idx; i < str.size(); i++)
        {
            string word = str.substr(idx, i - idx + 1);
            if(dict.find(word) == dict.end())
                continue;
            vector<string> next = getAll(i + 1, str, dict, dp);
            for(string &x : next)
                if(x.empty())
                    allCombi.push_back(word);
                else
                    allCombi.push_back(word + ' ' + x);
        }
        return dp[idx] = allCombi;
    }
    
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string &x : wordDict)
            dict.insert(x);
        unordered_map<int, vector<string>> dp;
        return getAll(0, str, dict, dp);
    }
};
