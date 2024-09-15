/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1598/problem/C
rating : 1200
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
	ll n;
	cin >> n;
	vector<ll> vec(n);
	ll sum = 0;
	for(ll& val : vec) {
		cin >> val;
		sum += val;
	}
	
	if(sum * 2 % n) {
		cout << "0\n";
		return;
	}
	ll ans = 0;
	map<ll , ll> rep;
	for(ll val : vec) {
		ans += rep[sum * 2 / n - val];
		rep[val]++;
	}
	
	cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}