/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/681/problem/B
 rating : 1300
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    ll n;
    cin >> n;
    for(ll i = 0 ; i * 1234567 <= n ; i++) {
        for(ll j = 0 ; i * 1234567 + j * 123456 <= n ; j++) {
            ll x = i * 1234567 + j * 123456;
            if((n - x) % 1234 == 0) {
            	cout << "YES";
            	return;
            }
        }
    }
    cout << "NO";
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