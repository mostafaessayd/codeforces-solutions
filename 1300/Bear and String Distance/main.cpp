/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/628/problem/C
 rating : 1300
 */


#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	int n , k;
	string s;
	cin >> n >> k >> s;
	string t = "";
	int i = 0;
	for( ; i < n && k ; i++) {
		bool a = ('z' - s[i] < s[i] - 'a');
		if(a) {
			if(s[i] - 'a' <= k) {
				t += 'a';
				k -= (s[i] - 'a');
			} else {
				t += (s[i] - k);
				k = 0;
			}
		} else {
			if('z' - s[i] <= k) {
				t += 'z';
				k -= ('z' - s[i]);
			} else {
				t += (s[i] + k);
				k = 0;
			}
		}
	}
	
	while(i < n) {
		t += s[i++];
	}
	
	if(k > 0) {
		cout << "-1";
	} else {
		cout << t;
	}
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
 // cin >> t;
  while (t--)
  {
    answer();
  }
  
  return 0;
}