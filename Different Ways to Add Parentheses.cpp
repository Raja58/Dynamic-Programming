// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Nov 2021
//  @Detail  :        Different Ways to Add Parentheses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int eval(int &x, int &y, char &c)
    {
        switch(c)
        {
            case '+' :
                return x + y;
            case '-' :
                return x - y;
            default :
                return x * y;
        }
        return -1;
    }
    
    vector<int> getAll(int start, int end, vector<int> &num, vector<char> &sym, vector<int> dp[12][12])
    {
        if(start == end)
            return vector<int> {num[start]};
        
        if(!dp[start][end].empty())
            return dp[start][end];
        
        vector<int> result;
        for(int i = start; i < end; i++)
        {
            vector<int> left = getAll(start, i, num, sym, dp);
            vector<int> right = getAll(i + 1, end, num, sym, dp);
            char c = sym[i];
            for(int &x : left)
                for(int &y : right)
                    result.push_back(eval(x, y, c));
        }
        return dp[start][end] = result;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int> num;    vector<char> sym;
        
        int start = 0;
        for(int i = 0; i < expression.size(); i++)
        {
            if(!isdigit(expression[i]))
            {
                sym.push_back(expression[i]);
                start = i + 1;
            }
            else
            {
                while(i < expression.size())
                    if(isdigit(expression[i]))
                        i++;
                    else
                        break;
                string temp = expression.substr(start, i - start);
                num.push_back(stoi(temp));
                i--;
            }
        }
        vector<int> dp[12][12];
        return getAll(0, num.size() - 1, num, sym, dp);
    }
};
