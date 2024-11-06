/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/960/problem/A
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
	string s;
	cin >> s;
	vector<int> rep(3 , 0);
	for(char& ch : s) {
		rep[ch - 'a']++;
	}
	
	if(rep[0] * rep[1] * rep[2] == 0) {
		cout << "NO";
		return;
	}
	
	if(!is_sorted(s.begin() , s.end())) {
		cout << "NO";
	} else {
		if(rep[1] == rep[2] || rep[0] == rep[2]) {
			cout << "YES";
		} else {
			cout << "NO";
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