// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        16 Nov 2021
//  @Detail  :        Cheapest Flights Within K Stops (LeetCode)
//  ============================
//  -->

class Solution {
public:
    struct detail{
        int node;
        int cost;
    };
    
    int getMinCost(int src, int k, int &dst, 
            vector<bool> vis, vector<vector<detail>> &graph, vector<vector<int>> &dp)
    {
        if(src == dst)
            return 0;
        if(k == -1)
            return INT_MAX;
        if(dp[src][k] != -1)
            return dp[src][k];
        
        vis[src] = true;
        int result = INT_MAX;
        for(detail &x : graph[src])
        {
            int temp = getMinCost(x.node, k - 1, dst, vis, graph, dp);
            if(temp != INT_MAX)
                temp += x.cost;
            if(result > temp)
                result = temp;
        }
        vis[src] = false;
        return dp[src][k] = result;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<detail>> graph(n);
        for(auto &x : flights)
            graph[x[0]].push_back({x[1], x[2]});
        vector<bool> vis(n, false);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int result =  getMinCost(src, k, dst, vis, graph, dp);
        return result != INT_MAX ? result : -1;
    }
};
