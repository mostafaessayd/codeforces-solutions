/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1023/problem/A
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
	string s , t;
	int n , m;
	cin >> n >> m >> s >> t;
	string left_s = "";
	string left_t = "";
	while(!s.empty() && !t.empty()) {
		if(s[0] == '*') {
			break;
		}
		left_s += s[0];
		left_t += t[0];
		s.erase(s.begin());
		t.erase(t.begin());
	}
	
	string right_s = "";
	string right_t = "";
	if(!s.empty()) {
		if(s[0] != '*') {
			cout << "NO";
			return;
		}
		s.erase(s.begin());
		reverse(s.begin() , s.end());
		reverse(t.begin() , t.end());
		while(!s.empty()) {
		  if(t.empty()) {
		  	cout << "NO\n";
		  	return;
		  }
		  right_s += s[0];
		  right_t += t[0];
		  s.erase(s.begin());
		  t.erase(t.begin());
	    }
	} else {
		if(t != s) {
			cout << "NO";
			return;
		}
	}
	
	cout << (right_t == right_s && left_s == left_t ? "YES" : "NO");
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