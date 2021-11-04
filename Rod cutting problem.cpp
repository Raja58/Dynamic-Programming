// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        04 Nov 2021
//  @Detail  :        Rod cutting problem
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;

int getMax(int idx, int cur, int &n, vector<int> &price, vector<vector<int>> &dp)
{
    if(idx == price.size() || cur == n)
        return 0;
    if(dp[idx][cur] != -1)
        return dp[idx][cur];
    int pick = INT_MIN, notPick = INT_MIN;
    if(cur + idx + 1 <= n)
        pick = price[idx] + getMax(idx, cur + idx + 1, n, price, dp);
    notPick = getMax(idx + 1, cur, n, price, dp);
    return dp[idx][cur] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
	return getMax(0, 0, n, price, dp);
}
