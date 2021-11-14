// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        14 Nov 2021
//  @Detail  :        Russian Doll Envelopes (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int isValid(vector<int> &big, vector<int> &small)
    {
        return big[0] > small[0] && big[1] > small[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envel) {
        sort(envel.begin(), envel.end());
        int n = envel.size(), result = 1;
        vector<int> count(n, 1), prev(n, -1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(!isValid(envel[i], envel[j]))
                    continue;
              
                if(count[i] < 1 + count[j])
                {
                    count[i] = 1 + count[j];
                    prev[i] = j;
                }
            }
            if(result < count[i])
                result = count[i];
        }
        return result;
    }
};
