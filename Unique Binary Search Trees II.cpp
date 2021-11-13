// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Nov 2021
//  @Detail  :        Unique Binary Search Trees II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<TreeNode *> getBST(int start, int end, vector<TreeNode *> dp[9][9])
    {
        if(start > end)
            return vector<TreeNode *>{NULL};
        
        if(!dp[start][end].empty())
            return dp[start][end];
        
        vector<TreeNode *> result;
        for(int i = start; i <= end; i++)
        {
            // TreeNode *root = new TreeNode(i); !!!!!  CAUTION !!!!!
            // It's wrong to declare here as it changes the previous ones as well.
            vector<TreeNode *> leftTree = getBST(start, i - 1, dp);
            vector<TreeNode *> rightTree = getBST(i + 1, end, dp);
            
            for(TreeNode *x : leftTree)
                for(TreeNode *y : rightTree)
                {
                    TreeNode *root = new TreeNode(i);
                    root -> left = x;
                    root -> right = y;
                    result.push_back(root);
                }
        }
        return dp[start][end] = result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> dp[9][9];
        return getBST(1, n, dp);
    }
};
