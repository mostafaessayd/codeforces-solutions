/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1076/problem/A
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
	string s;
	cin >> n >> s;
	bool found = false;
	for(int i = 0 ; i < n - 1 ; i++) {
		if(s[i] > s[i + 1]) {
			found = true;
			s[i] = '.';
			break;
		}
	}
	
	if(!found) {
		s[n - 1] = '.';
	}
	
	for(char& c : s) {
		if(c != '.') {
			cout << c;
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