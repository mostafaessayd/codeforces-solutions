/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1928/problem/B
rating : 1200
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	map<int , int> cnt;
	vector<int> dp;
	for(int& val : vec) {
		cin >> val;
		if(cnt[val] == 0) {
			dp.push_back(val);
		}
		cnt[val]++;
	}
    
	sort(dp.begin() , dp.end());

	int m = dp.size();
	int j = 0;
	int ans = 0;
	for(int i = 0 ; i < m ; i++) {
		while(j < m && dp[j] - dp[i] < n) {
			j++;
		}

		ans = max(ans , j - i);
		if(j == m) {
			break;
		}
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