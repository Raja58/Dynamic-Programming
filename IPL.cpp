// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        06 Nov 2021
//  @Detail  :        Problem Code: ZCO14004 (CodeChef)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long

int getMax(int idx, int prevMatch, int &n, vector<int> &input, vector<vector<int>> &dp)
{
    if(idx == n)
        return 0;
  
    if(dp[idx][prevMatch] != -1)
        return dp[idx][prevMatch];

    int pick = INT_MIN;
    if(prevMatch < 2)
        pick = input[idx] + getMax(idx + 1, prevMatch + 1, n, input,dp);
    int notPick = getMax(idx + 1, 0, n, input, dp);
    return dp[idx][prevMatch] = max(pick, notPick);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int n;  cin>>n;
    vector<int> input(n);
    for(int i = 0; i < n; i++)
        cin>>input[i];
    vector<vector<int>> dp(n + 1 ,vector<int>(3, -1));
    cout<<getMax(0, 0, n, input, dp);
    return 0;
}
