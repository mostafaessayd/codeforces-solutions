/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1800/problem/D
rating : 1200
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long;

void answer() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for(int i = 1 ; i < n - 1 ; i++) {
    	ans += (s[i - 1] != s[i + 1]);
    }
    
    cout << ans << '\n';
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