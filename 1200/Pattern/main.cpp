/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/412/problem/C
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
	vector<string> vec(n);
	for(string& val : vec) cin >> val;
	
	int m = vec[0].size();
	for(int i = 0 ; i < m ; i++) {
		vector<int> rep(26 , 0);
		int diff = 0;
		char ch;
		for(int j = 0 ; j < n ; j++) {
			if(vec[j][i] == '?') {
				continue;
			}
			if(rep[vec[j][i] - 'a'] == 0) {
				ch = vec[j][i];
				diff++;
				rep[vec[j][i] - 'a']++;
			}
		}
		if(diff == 0) {
			cout << 'a';
		} else {
			if(diff == 1) {
				cout << ch;
			} else {
				cout << '?';
			}
		}
	}
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