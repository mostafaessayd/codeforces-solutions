/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1555/problem/C
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(2 , vector<int>(n));
    vector<vector<int>> prefix(2 , vector<int>(n , 0));

    for(int i = 0 ; i < 2 ; i++) {
        int sum = 0;
        for(int j = 0 ; j < n ; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
            prefix[i][j] = sum;
        }
    }
    
    if(n == 1) {
        cout << "0\n";
        return;
    }

    int ans = min(prefix[1][n - 2] , prefix[0][n - 1] - vec[0][0]);
    for(int i = 1 ; i < n - 1 ; i++) {
        ans = min(ans , max(prefix[1][i - 1] , prefix[0][n - 1] - prefix[0][i]));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
     cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}