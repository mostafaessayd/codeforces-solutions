/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/611/problem/B
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    ll a , b;
    cin >> a >> b;

    auto getValueOf = [&](string& binary) -> ll {
        int p = 0;
        ll res = 0;
        for(int i = binary.size() - 1 ; i >= 0 ; i-- , p++) {
            res += (binary[i] - '0') * pow(2 , p);
        }

        return res;
    };
    
    int ans = 0;
    for(int i = 2 ; i <= 60 ; i++) {
        string t = "0";
        for(int j = 0 ; j < i - 1 ; j++) {
            t = "1" + t;
        }
        ll x = getValueOf(t);
        ans += (x >= a && x <= b);
        for(int j = i - 1 ; j > 0 ; j--) {
            swap(t[j] , t[j - 1]);
            if(t[0] == '0') continue;
            ll x = getValueOf(t);
            ans += (x >= a && x <= b);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}



