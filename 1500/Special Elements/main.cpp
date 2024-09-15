/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1352/problem/E
rating : 1500
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	vector<ll> vec(n);
	vector<int> cnt(n + 1 , 0);
	for(ll& val : vec) {
		cin >> val;
		cnt[val]++;
	}
    
	vector<int> vis(n + 1 , 0);
	int ans = 0;
	for(int i = 0 ; i < n ; i++) {
		ll sum = 0;
		for(int j = i ; j < n ; j++) {
			sum += vec[j];
			if(sum > n) {
				break;
			}
			if(j > i) {
			  vis[sum] = 1;
			}
		}
	}

	for(int i = 0 ; i < n ; i++) {
		ans += vis[vec[i]];
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