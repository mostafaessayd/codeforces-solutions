/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/145/problem/A
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
	string a , b;
	cin >> a >> b;
	int n = a.size();
	int s1 = 0 , s2 = 0;
	for(int i = 0 ; i < n ; i++) {
		if(a[i] != b[i]) {
			s1 += (a[i] == '4');
			s2 += (a[i] == '7');
		}
	}
	
	cout << max(s1 , s2);
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