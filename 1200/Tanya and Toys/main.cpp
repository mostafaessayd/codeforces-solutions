/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/659/problem/C
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
	int n , m;
	cin >> n >> m;
	vector<int> vec(n);
	for(int& val : vec) cin >> val;
	int l = 1;
	vector<int> ans;
	sort(vec.begin() , vec.end());
	int i = 0;
	while(m > 0 && i < n) {
		if(l == vec[i]) {
			l++;
			i++;
		} else {
			if(l > m) break;
			m -= l;
			ans.push_back(l);
			l++;
		}
	}
	
	if(i == n) {
		l += (l == vec[n - 1]);
		while(m > 0) {
			if(l > m) break;
			m -= l;
			ans.push_back(l);
			l++;
		}
	}
	
	cout << ans.size() << '\n';
	for(int ind : ans) cout << ind << ' ';
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