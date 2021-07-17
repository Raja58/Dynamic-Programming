// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Jul 2021
//  @Detail  :        369digit (SPOJ)
//  ============================
//  -->
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod (int)(1e9+7)
int cache[2][18][18][18][52];

int getAll369(int idx, int flag, vector<int> &a, vector<int> track)
{
    if(idx == a.size())
    {
        if(track[1] && track[1] == track[2] && track[2] == track[3])
            return 1;
        return 0;
    }

    if(cache[flag][track[1]][track[2]][track[3]][idx] != -1)
        cache[flag][track[1]][track[2]][track[3]][idx];

    int limit = flag ? a[idx] : 9, count = 0;

    for(int num = 0; num <= limit; num++)
    {        
        if(flag && num == a[idx])
        {
            if(num && !(num % 3))
            {
                if(track[num / 3] < a.size() / 3)
                {
                    track[num / 3]++;
                    count = (count + getAll369(idx + 1, 1, a, track)) % mod;
                    track[num / 3]--;
                }
            }
            else
                count = (count + getAll369(idx + 1, 1, a, track)) % mod;
                
        }
        else
        {
            if(num && !(num % 3))
            {
                if(track[num / 3] < a.size() / 3)
                {
                    track[num / 3]++;
                    count = (count + getAll369(idx + 1, 0, a, track)) % mod;
                    track[num / 3]--;
                }
            }
            else
                count = (count + getAll369(idx + 1, 0, a, track)) % mod;
        }
    }
    return cache[flag][track[1]][track[2]][track[3]][idx] = count;
}

int get(string &str)
{
    vector<int> a(str.size());
    int i = 0;
    while(i < str.size())
    {
        a[i] = (str[i] - '0');
        i++;
    }
    memset(cache, -1, sizeof(cache));
    vector<int> track{-1, 0, 0, 0};
    return getAll369(0, 1, a, track);
}

int brut(string &str)
{
    int i = 0;
    vector<int> track{-1, 0, 0, 0};
    while(i < str.size())
    {
        if((str[i] - '0') % 3 == 0)
            track[(str[i] - '0') / 3]++;
        i++;
    }
    return track[1] && track[1] == track[2] && track[2] == track[3];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        string l, r;   cin>>l>>r;
        cout<<get(r) - get(l) + brut(l)<<"\n";
    }
    return 0;
}