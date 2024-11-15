/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1029/problem/B
rating : 1200
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
const int Mod = 1e9 + 7;

void answer() {
	int n;
	cin >> n;
	vector<ll> vec(n);
	for(ll& val : vec) cin >> val;
	int ans = 0;
	int l = 1;
    for(int i = 1 ; i < n ; i++) {
    	if(vec[i - 1] * 2 >= vec[i]) {
    		l++;
    	} else {
    		ans = max(ans , l);
    		l = 1;
    	}
    }
    ans = max(ans , l);
    		l = 1;
	cout << ans << '\n';
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