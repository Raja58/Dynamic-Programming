// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        03 Nov 2021
//  @Detail  :        House Robber III (LeetCode)
//  ============================
//  -->

class Solution {
public:
    pair<int, int> getSoul(TreeNode* root, unordered_map<TreeNode*, pair<int, int>> &dp)
    {
        if(!root)
            return {0, 0};
        if(dp.find(root) != dp.end())
            return dp[root];
      
        pair<int, int> leftTree = getSoul(root -> left, dp), rightTree = getSoul(root -> right, dp);
        int pick = root -> val + leftTree.second + rightTree.second;
        int notPick = max(leftTree.first, leftTree.second) + max(rightTree.first, rightTree.second);
        return dp[root] = {pick, notPick};
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> dp;
        pair<int, int> result = getSoul(root, dp);
        return max(result.first, result.second);
    }
};
