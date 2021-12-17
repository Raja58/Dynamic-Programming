// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Dec 2021
//  @Detail  :        Sum of all substrings of a number (GFG)
//  ============================
//  -->

class Solution
{
    public:
    int mod = 1000000007;
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string str){
        long long result = 0, temp = 0;
        for(int i = 0; i < str.size(); i++)
        {
            temp = (temp * 10 + (i + 1) * (str[i] - '0')) % mod;
            result = (result + temp) % mod;
        }
        return result;
    }
};
