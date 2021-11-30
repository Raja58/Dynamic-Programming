// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        30 Nov 2021
//  @Detail  :        Maximum Earnings From Taxi (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getNextIdx(int x, int start, vector<vector<int>> &rides)
    {
        int low = start, high = rides.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(rides[mid][0] >= x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low < rides.size() ? low : -1;
    }
    
    long long getMaxDollar(int idx, vector<vector<int>> &rides, vector<long long> &dp)
    {
        if(idx == rides.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int nextIdx = getNextIdx(rides[idx][1], idx + 1, rides);
        long long pick = rides[idx][1] - rides[idx][0] + rides[idx][2];
        if(nextIdx != -1)
            pick += getMaxDollar(nextIdx, rides, dp);
        long long notPick = getMaxDollar(idx + 1, rides, dp);
        
        return dp[idx] = max(pick, notPick);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size() + 1, -1);
        return getMaxDollar(0, rides, dp);
    }
};
