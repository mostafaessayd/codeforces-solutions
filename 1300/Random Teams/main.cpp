/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/478/problem/B
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;

void answer() {
    ll n , m;
    cin >> n >> m;
    ll all_frindes = n / m;
    
    ll min_friends = ((all_frindes * (all_frindes + 1)) / 2) * (n % m);
    min_friends += ((all_frindes * (all_frindes - 1)) / 2) * (m - n % m);
    ll max_friends = n - m;
    max_friends = ((max_friends + 1) * max_friends) / 2;
    cout << min_friends << ' ' << max_friends;
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