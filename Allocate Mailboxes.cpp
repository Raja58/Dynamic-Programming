// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Mar 2026
//  @Detail  :        Allocate Mailboxes (Leetcode)
//  ============================
//  -->
class Solution {
public:

    int getMedianDistance(int startIdx, int endIdx, vector<int> &houses)
    {        
        int medianIdx = startIdx + (endIdx - startIdx) / 2;
        int mailBoxPosition = houses[medianIdx];

        int result = 0;
        for(int idx = startIdx; idx <= endIdx; idx++)
        {
            result += abs(houses[idx] - mailBoxPosition);
        }

        return result;
    }
    
    int getMinDistance(int startIdx, int endIdx, int noOfMailBox, vector<int> &houses, vector<vector<vector<int>>> &cache)
    {
        if(noOfMailBox == 0)
        {
            if(endIdx >= houses.size())
                return 0;
            return INT_MAX;
        }
        
        if(cache[startIdx][endIdx][noOfMailBox] != INT_MAX)
            return cache[startIdx][endIdx][noOfMailBox];

        // No Cut
        int noCut = INT_MAX;
        if(endIdx < houses.size() - noOfMailBox)
            noCut = getMinDistance(startIdx, endIdx + 1, noOfMailBox, houses, cache);
        
        // Cut
        int cut = getMinDistance(endIdx + 1, endIdx + 1, noOfMailBox - 1, houses, cache);
        if(cut != INT_MAX)
            cut += getMedianDistance(startIdx, endIdx, houses);

        return cache[startIdx][endIdx][noOfMailBox] = min(noCut, cut);
    }

    int minDistance(vector<int>& houses, int k) {
        if(k >= houses.size())
            return 0;
        sort(houses.begin(), houses.end());
        vector<vector<vector<int>>> cache(houses.size() + 1, vector<vector<int>>(houses.size() + 1, vector<int>(k + 1, INT_MAX)));
        return getMinDistance(0, 0, k, houses, cache);
    }
};
