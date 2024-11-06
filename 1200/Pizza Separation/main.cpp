/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/895/problem/A
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;
using ll = long long;

void answer()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int& val : vec) cin >> val;
	
	int ans = 360;
	for(int i = 0 ; i < n ; i++) {
		int sum = 0;
		for(int j = i ; j < n ; j++) {
			sum += vec[j];
			ans = min(ans , abs(360 - 2 * sum));
		}
	}
	cout << ans;
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