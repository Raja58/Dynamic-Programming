// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Nov 2021
//  @Detail  :        Count Numbers with Unique Digits (LeetCode)
//  ============================
//  --> 

class Solution {
public:
    
    int getUniqueDig(int idx, int mask, bool started, int &n, int dp[9][1 << 10][2])
    {
        if(idx == n)
            return 1;
        
        if(dp[idx][mask][started] != -1)
            return dp[idx][mask][started];
        
        int cnt = 0;
        for(int i = 0; i <= 9; i++)
        {
            if(started)
            {
                if(mask & (1 << i))
                    continue;
              
                mask |= (1 << i);
                cnt += getUniqueDig(idx + 1, mask, started, n, dp);
                mask ^= (1 << i);
            }
            else
            {
                if(i == 0)
                    cnt += getUniqueDig(idx + 1, mask, started, n, dp);
                else
                {
                    mask |= (1 << i);
                    cnt += getUniqueDig(idx + 1, mask, true, n, dp);
                    mask ^= (1 << i);
                }
            }
            
        }
        return dp[idx][mask][started] = cnt;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int dp[9][1 << 10][2];
        memset(dp, -1, sizeof(dp));
        return getUniqueDig(0, 0, false, n, dp);
    }
};
