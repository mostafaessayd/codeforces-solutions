/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1954/problem/B
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> vec[i];
	}
	
	int ans = 1e9;
	int last = -1;
	for(int i = 0 ; i < n ; i++) {
		if(vec[i] != vec[0]) {
			ans = min(ans , i - last - 1);
			last = i;
		}
	}
	
	ans = min(ans , n - last - 1);
	cout << (ans == n ? -1 : ans) << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}