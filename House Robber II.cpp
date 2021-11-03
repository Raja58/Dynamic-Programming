// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        03 Nov 2021
//  @Detail  :        House Robber II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getSoul(int idx, int n, bool prevUsed, vector<int> &nums, int dp[101][2])
    {
        if(idx == n)
            return 0;
        if(dp[idx][prevUsed] != -1)
            return dp[idx][prevUsed];
        int pick = INT_MIN, notPick = INT_MAX;
        if(!prevUsed)
            pick = nums[idx] + getSoul(idx + 1, n, true, nums, dp);
        notPick = getSoul(idx + 1, n, false, nums, dp);
        return dp[idx][prevUsed] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0]; //very very important edge case
       int dp[101][2];
        memset(dp, -1, sizeof(dp));
        int first = getSoul(0, n - 1, false, nums, dp);
        memset(dp, -1, sizeof(dp));
        int last = getSoul(1, n, false, nums, dp);
        return max(first, last);
    }
};
