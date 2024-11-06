/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1355/problem/A
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    ll a , k;
    cin >> a >> k;

    auto get = [&](ll x)-> pair<int , int> {
        int min_dg = 10;
        int max_dg = 0;
        while(x > 0) {
            int y = x % 10;
            min_dg = min(min_dg , y);
            max_dg = max(max_dg , y);
            x /= 10;
        }

        return {min_dg , max_dg};
    };
  
    while(k-- > 1) {
        pair<int , int> u = get(a);
        if(u.first * u.second == 0) break;
        a += u.first * u.second;
    }

    cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}