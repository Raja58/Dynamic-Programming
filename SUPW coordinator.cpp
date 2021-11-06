// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        06 Nov 2021
//  @Detail  :        Problem Code: ZCO14002 (CodeChef)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long

int getMin(int idx, int freeDays, int &n, vector<int> &input, vector<vector<int>> &dp)
{
    if(idx == n)
        return 0;
        
    if(dp[idx][freeDays] != -1)
        return dp[idx][freeDays];
    
    int pick = input[idx] + getMin(idx + 1, 0, n, input, dp);
    int notPick = INT_MAX;
    if(freeDays < 2)
        notPick = getMin(idx + 1, freeDays + 1, n, input, dp);
    return dp[idx][freeDays] = min(pick, notPick);
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
    cout<<getMin(0, 0, n, input, dp);
    return 0;
}
