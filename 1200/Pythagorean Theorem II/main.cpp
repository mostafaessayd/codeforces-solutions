/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/304/problem/A
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
	int n;
	cin >> n;
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			ans += (i * i + j * j <= n * n && ((int)sqrt(i * i + j * j) * (int)sqrt(i * i + j * j) == i * i + j * j));
		}
	}
	
	cout << ans / 2;
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