/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1384/problem/A
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
	
	vector<string> ans(n + 1 , "");
	for(int i = 0 ; i <= n ; i++) {
		for(int j = 1 ; j <= 200 ; j++) {
			ans[i] += 'a';
		}
	}
	
	for(int i = 1 ; i <= n ; i++) {
		ans[i] = ans[i - 1];
		ans[i][vec[i - 1]] = (ans[i][vec[i - 1]] == 'a' ? 'b' : 'a');
	}
	
	for(int i = 0 ; i <= n ; i++) {
		cout << ans[i] << "\n";
	}
	//cout << "\n\n";
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