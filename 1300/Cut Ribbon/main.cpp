/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/4/C
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

void answer()
{
    int n, a, b,c;
    cin >> n >> a >> b >> c;

    auto MaxSplit = [&](auto self, int n, int a, int b, int c, vector<int>& rep)->int
    {
        if(n == 0)
            return 0;
            
        if(n < 0)
            return INT_MIN;
            
        if(rep[n] != -1)
            return rep[n];
            
        int split_a = 1 + self(self, n - a, a, b, c, rep);
        int split_b = 1 + self(self, n - b, a, b, c, rep);
        int split_c = 1 + self(self, n - c, a, b, c, rep);

        return rep[n] = max({split_a, split_b, split_c});
    };

    vector<int>rep(4001, -1);

    cout << MaxSplit(MaxSplit, n, a, b, c, rep) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    //cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}