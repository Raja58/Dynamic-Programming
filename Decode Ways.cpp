// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        08 Nov 2021
//  @Detail  :        Decode Ways (LeetCode)
//  ============================
//  -->

int getSoul(int idx, string &str, vector<int> &dp)
    {
        if(idx == str.size())
            return 1;
            
        if(dp[idx] != -1)
            return dp[idx];
            
        if(str[idx] == '0')
            return 0;
        int cnt = 0;
        for(int len : {1, 2})
        {
            if(idx + len > str.size())
                break;
            string word = str.substr(idx, len);    
            int num = stoi(word);
            if(num <= 26)
                cnt += getSoul(idx + len, str, dp);
        }
        return dp[idx] = cnt;
    }
    
    int numDecodings(string str) {
        vector<int> dp(str.size(), -1);
        return getSoul(0, str, dp);
    }
