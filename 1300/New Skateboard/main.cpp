/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/628/problem/B
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
	string s;
	cin >> s;
	ll ans = ((s[0] - '0') % 4 == 0);
	for(int i = 1 ; i < s.size() ; i++) {
	   ans += ((s[i] - '0') % 4 == 0);
	   int d = (s[i - 1] - '0') * 10 + (s[i] - '0');
	   if(d % 4 == 0) {
	   	ans += 1ll * i;
	   }
	}
	
	cout << ans;
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