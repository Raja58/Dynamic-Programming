// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Nov 2021
//  @Detail  :        Scramble String (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    string getKey(string x, string y)
    {
        return x + '-' + y;
    }
    
    bool isValid(string s, string t, unordered_map<string, bool> &dp)
    {
        if(s == t)
            return true;

        string key = getKey(s, t);
        if(dp.find(key) != dp.end())
            return dp[key];
        
        for(int i = 1; i < s.size(); i++)
        {
            bool asItIs = isValid(s.substr(0, i), t.substr(0, i), dp) && isValid(s.substr(i), t.substr(i), dp);
             if(asItIs)
                return dp[key] = true;
            bool swapped = isValid(s.substr(i), t.substr(0, s.size() - i), dp) && isValid(s.substr(0, i), t.substr(t.size() - i), dp);
            if(swapped)
                return dp[key] = true;
        }
        return dp[key] = false;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        return isValid(s1, s2, dp);
    }
};
