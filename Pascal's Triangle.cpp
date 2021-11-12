// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Nov 2021
//  @Detail  :        Pascal's Triangle (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        vector<int> cache(n);
        cache[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            vector<int> temp(i);    temp[0] = 1;
            for(int j = i - 1; j > 0; j--)
                temp[j] = cache[j] = cache[j] + cache[j - 1];
            result.push_back(temp);
        }
        return result;
    }
};
