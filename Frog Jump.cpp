// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        14 Nov 2021
//  @Detail  :        Frog Jump (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isPossible(int k, int cur, int target,
            unordered_set<int> &stone, set<pair<int, int>> &dp)
    {
        if(cur == target)
            return true;
        if(dp.find({k, cur}) != dp.end())
            return false;
        for(int i : {-1, 0, 1})
            if(k + i != 0 && stone.find(cur + k + i) != stone.end())
                if(isPossible(k + i, cur + k + i, target, stone, dp))
                    return true;
        dp.insert({k, cur});
        return false;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        unordered_set<int> stone;
        for(int &x : stones)
            stone.insert(x);
        set<pair<int, int>> cache;
        return isPossible(1, stones[1], stones.back(), stone, cache);
    }
};
