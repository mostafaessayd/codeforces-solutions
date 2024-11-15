/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1042/problem/B
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
	map<string , ll> c;
	c["A"] = 1e9;
	c["B"] = 1e9;
	c["C"] = 1e9;
	c["AB"] = 1e9;
	c["AC"] = 1e9;
	c["BC"] = 1e9;
	c["ABC"] = 1e9;
	
	for(int i = 0 ; i < n ; i++) {
		ll cost;
		string s;
		cin >> cost >> s;
		sort(s.begin() , s.end());
		c[s] = min(c[s] , cost);
	}
	
	ll ans = c["ABC"];
	ans = min(ans , c["A"] + c["BC"]);
	ans = min(ans , c["B"] + c["AC"]);
	ans = min(ans , c["C"] + c["AB"]);
	ans = min(ans , c["A"] + c["B"] + c["C"]);
	ans = min(ans , c["AB"] + c["BC"]);
	ans = min(ans , c["AC"] + c["BC"]);
	ans = min(ans , c["AC"] + c["AB"]);
	
	cout << (ans >= 1e9 ? -1 : ans);
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