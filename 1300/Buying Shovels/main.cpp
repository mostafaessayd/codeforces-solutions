/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1360/problem/D
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;

void answer() {
    int n , k;
    cin >> n >> k;
    int max_divisor = -1;
    for(int i = 1 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            if(i <= k) {
                max_divisor = max(max_divisor , i);
            }
            if(i != n / i) {
                if(n / i <= k) {
                    max_divisor = max(max_divisor , n / i);
                }
            }
        }
    }

    cout << n / max_divisor << '\n';
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