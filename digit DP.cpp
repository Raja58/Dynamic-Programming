<!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Jul 2021
//  @Detail  :        digitDP (code Forces)
//  ============================
//  -->
#include <bits/stdc++.h>
using namespace std;
#define int long long

int getAll(int idx, int flag, int fd, int ld, vector<int> &a, int cache[100][2][10][10])
{
    if(idx == a.size())
        return fd == ld ? 1 : 0;
    if(cache[idx][flag][fd][ld] != -1)
        return cache[idx][flag][fd][ld];
    int limit = flag ? a[idx] : 9, count = 0;
    for(int num = 0; num <= limit; num++)
    {
        if(fd == 0)
        {
            if(flag && num == a[idx])
                count += getAll(idx + 1, 1, num, num, a, cache);
            else
                count += getAll(idx + 1, 0, num, num, a, cache);
        }
        else
        {
            if(flag && num == a[idx])
                count += getAll(idx + 1, 1, fd, num, a, cache);
            else
                count += getAll(idx + 1, 0, fd, num, a, cache);
        }
    }
    return cache[idx][flag][fd][ld] = count;
}

int get(int x)
{
    vector<int> a;
    while(x)
    {
        int temp = x % 10;
        a.push_back(temp);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    int cache[100][2][10][10];
    memset(cache, -1, sizeof(cache));
    return getAll(0, 1, 0, 0, a, cache);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int l, r;   cin>>l>>r;
    if(l)
        cout<<get(r) - get(l - 1);
    else
        cout<<get(r);
    return 0;
}
