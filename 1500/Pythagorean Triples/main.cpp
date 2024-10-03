/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1409/problem/D
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;

map<ll , int> cnt;
vector<ll> all_squars;

void answer() {
    ll n;
    cin >> n;
    int ans = -1;
    for(int i = 0 ; i < all_squars.size() ; i++) {
        ans += ((all_squars[i] & 1) && all_squars[i] <= 2 * n - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(ll i = 1 ; i * i <= 2 * 1e9 ; i++) {
        cnt[i * i]++;
        all_squars.push_back(i * i);
    }
    
    int t = 1;
    cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}