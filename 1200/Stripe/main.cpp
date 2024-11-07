/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/18/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int tot = 0;
    for(int& val : vec) {
        cin >> val;
        tot += val;
    }

    int ways = 0;
    int prefix = 0;
    for(int i = 0 ; i < n - 1 ; i++) {
        prefix += vec[i];
        tot -= vec[i];
        ways += (prefix == tot);
    }

    cout << ways << '\n';
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