// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Video Stitching (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMinClip(int idx, int start, int end, vector<vector<int>> &clips, vector<vector<int>> &dp)
    {
        if(start >= end)
            return 0;
        
        if(idx == clips.size())
            return INT_MAX;
        
        if(dp[idx][start] != -1)
            return dp[idx][start];
        
        int pick = INT_MAX, notPick = INT_MAX;
        if(clips[idx][0] <= start)
            pick = getMinClip(idx + 1, clips[idx][1], end, clips, dp);
        if(pick != INT_MAX)
            pick += 1;
        notPick = getMinClip(idx + 1, start, end, clips, dp);
        return dp[idx][start] = min(pick, notPick);
    }
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
      
        vector<vector<int>> dp(clips.size() + 1, vector<int>(1001, -1));
        int result = getMinClip(0, 0, time, clips, dp);
        return result != INT_MAX ? result : -1;
    }
};
