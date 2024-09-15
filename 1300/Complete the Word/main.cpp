/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/716/problem/B
 rating : 1300
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0 ; i <= n - 26 ; i++) {
		vector<int> rep(26 , 0);
		vector<int> qt;
		bool unique = true;
		for(int j = i ; j < i + 26 ; j++) {
			if(s[j] == '?') {
			  qt.push_back(j);
				continue;
			}

			if(rep[s[j] - 'A']) {
				unique = false;
				break;
			}
			rep[s[j] - 'A']++;
		}
		
		if(unique) {
			int j = 0;
			for(int k = 0 ; k < 26 && j < qt.size() ; k++) {
				if(rep[k]) {
					continue;
				}
				rep[k]++;
				s[qt[j++]] = k + 'A';
			}
			
			for(int k = 0 ; k < n ; k++) {
				s[k] = (s[k] == '?' ? 'B' : s[k]);
			}
			cout << s;
			return;
		}
	}
	
	cout << "-1";
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}