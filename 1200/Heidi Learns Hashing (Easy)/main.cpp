/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1184/problem/A1
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
int N = 2e5 + 1;

void answer()
{
	ll r;
	cin >> r;
	for(ll i = 1 ; i * i <= 1e12 ; i++) {
		ll n = (r - i * i - i - 1);
		if(n % (2 * i) == 0 && n > 0) {
			cout << i << ' ' << n / (2 * i);
			return;
		}
	}
	cout << "NO";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}