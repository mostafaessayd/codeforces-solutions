/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1121/problem/B
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
int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int& val : vec) cin >> val;
	
	vector<vector<int>> sums(2e5 + 1);
	int ans = 0;
	for(int i = 0 ; i < n - 1 ; i++) {
		for(int j = i + 1 ; j < n ; j++) {
			int sum = vec[i] + vec[j];
			bool a = binary_search(sums[sum].begin() , sums[sum].end() , vec[i]);
			bool b = binary_search(sums[sum].begin() , sums[sum].end() , vec[j]);
			if(!a && !b) {
				sums[sum].push_back(vec[i]);
				sums[sum].push_back(vec[j]);
				ans = max(ans , ((int)sums[sum].size()) / 2);
			}
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