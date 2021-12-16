// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        16 Dec 2021
//  @Detail  :        Max sum subarray by removing at most one element (GFG)
//  ============================
//  -->

int maxSumSubarray(int arr[], int n)
    {
        int sum = 0, result = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int x = arr[i];
            sum += x;
            if(result < sum)
                result = sum;
            if(sum < 0)
                sum = 0;
        }
        
        int left[n], right[n];
        left[0] = arr[0];
        for(int i = 1; i < n; i++)
            left[i] = max(arr[i], arr[i] + left[i - 1]);
            
        right[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--)
            right[i] = max(arr[i], arr[i] + right[i + 1]);
            
        for(int i = 1; i < n - 1; i++)
            result = max(result, left[i - 1] + right[i + 1]);
            
        return result;
    }
