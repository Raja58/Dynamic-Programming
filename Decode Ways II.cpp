// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        08 Nov 2021
//  @Detail  :        Decode Ways II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int mod = 1000000007;
    
    long long getSoul(int idx, string &str, vector<int> &dp)
    {
        if(idx == str.size())
            return 1;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        if(str[idx] == '0')
            return 0;
        
        long long cnt = 0;
        
//         for single digit
        if(str[idx] != '*')
            cnt = (cnt + getSoul(idx + 1, str, dp)) % mod;
        else
            cnt = (cnt + (9 * getSoul(idx + 1, str, dp)) % mod) % mod;
        
//         for double digit
        if(str[idx] != '*' && str[idx] > '2')
            return cnt;
        if(idx + 1 >= str.size())
            return cnt;
        
        if(str[idx] != '*' && str[idx + 1] != '*')
        {
            if(stoi(str.substr(idx, 2)) <= 26)
                cnt = (cnt + getSoul(idx + 2, str, dp)) % mod;
        }
        else if(str[idx] == '*' && str[idx + 1] == '*')
            cnt = (cnt + (15 * getSoul(idx + 2, str, dp)) % mod) % mod;
        else if(str[idx] == '*')
            for(char c : {'1', '2'})
            {
                string word = "";
                word = word + c + str[idx + 1];
                if(stoi(word) <= 26)
                    cnt = (cnt + getSoul(idx + 2, str, dp)) % mod;
            }
        else
        {
            if(str[idx] == '1')
                cnt = (cnt + (9 * getSoul(idx + 2, str, dp)) % mod) % mod;
            else
                cnt = (cnt + (6 * getSoul(idx + 2, str, dp)) % mod) % mod;
        }
        
        return dp[idx] = cnt;
    }
    
    int numDecodings(string str) {
        vector<int> dp(str.size() + 1, -1);
        return (int)getSoul(0, str, dp);
    }
};
