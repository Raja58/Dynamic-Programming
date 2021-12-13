// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Dec 2021
//  @Detail  :        Maximal Square (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size()));
        int maxi = 0;
        for(int i=0; i<matrix.size(); i++)
        {
            cache[i][0] = matrix[i][0] == '1' ? 1 : 0;
            if(cache[i][0])
                maxi = 1;
        }
        for(int j=0; j<matrix[0].size(); j++)
        {
            cache[0][j] = matrix[0][j] == '1' ? 1 : 0;
            if(cache[0][j])
                maxi = 1;
        }
        for(int i=1; i<matrix.size(); i++)
            for(int j=1; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                    cache[i][j] = 1 + min({cache[i-1][j-1], cache[i][j-1], cache[i-1][j]});
                if(cache[i][j] > maxi)
                    maxi = cache[i][j];
            }
        return pow(maxi, 2);
    }
};
