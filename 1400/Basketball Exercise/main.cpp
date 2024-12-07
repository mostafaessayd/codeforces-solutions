/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1195/problem/C
rating : 1400
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n) , b(n);
	for(ll& val : a) cin >> val;
	for(ll& val : b) cin >> val;
	vector<vector<ll>> dp(n , vector<ll>(2 , -1));
	
	auto f = [&](auto self , int idx , int d) -> ll {
		if(idx == n) return 0;
		if(~dp[idx][d]) return dp[idx][d];
		ll ans = self(self , idx + 1 , d);
		if(d == 1) {
			ans = max(ans , a[idx] + self(self , idx + 1 , 0));
		} else {
			ans = max(ans , b[idx] + self(self , idx + 1 , 1));
		}
		
		return dp[idx][d] = ans;
	};
	
	cout << max(f(f , 0 , 1) , f(f , 0 , 0));
    return 0;
}