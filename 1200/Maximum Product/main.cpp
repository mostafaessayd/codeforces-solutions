/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1406/problem/B
rating : 1200
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	vector<ll> vec;
	bool zo = false;
	for(int i = 0 ; i < n ; i++) {
		ll val;
		cin >> val;
		if(val != 0) {
			vec.push_back(val);
		} else {
			zo = true;
		}
	}
	
	sort(vec.begin() , vec.end());
	
	if(vec.size() < 5) {
		cout << "0\n";
		return;
	}
	
	if(vec.back() < 0) {
		ll ans = -1e18;
		n = vec.size();
		ans = max(ans , vec[n - 1] * vec[n - 2] * vec[n - 3] * vec[n - 4] * vec[n - 5]);
		if(zo) {
			ans = max(1ll * ans , 0LL);
		}
		cout << ans << '\n';
	} else {
		ll ans = -1e18;
		n = vec.size();
		ans = max(1ll * ans , 1ll * (vec[n - 1] * vec[n - 2] * vec[n - 3] * vec[n - 4] * vec[n - 5]));
		ans = max(1ll * ans , 1ll * (vec[n - 1] * vec[n - 2] * vec[n - 3] * vec[n - 4] * vec[0]));
		ans = max(1ll * ans , 1ll * (vec[n - 1] * vec[n - 2] * vec[n - 3] * vec[1] * vec[0]));
		ans = max(1ll * ans , 1ll * (vec[n - 1] * vec[n - 2] * vec[2] * vec[1] * vec[0]));
		ans = max(1ll * ans , 1ll * (vec[n - 1] * vec[3] * vec[2] * vec[1] * vec[0]));
		ans = max(1ll * ans , 1ll * (vec[4] * vec[3] * vec[2] * vec[1] * vec[0]));
		
		if(zo) {
			ans = max(1ll * ans , 0LL);
		}
		
		cout << ans << '\n';
	}
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