/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/828/problem/A
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
	int n , a , b;
	cin >> n >> a >> b;
	vector<int> vec(n);
	for(int& val : vec) cin >> val;
	int c = 0;
	int ans = 0;
	for(int i = 0 ; i < n ; i++) {
		if(vec[i] == 1) {
			if(a > 0) {
				a--;
			} else {
				if(b > 0) {
					b--;
					c++;
				} else {
					if(c > 0) {
						c--;
					} else {
						ans++;
					}
				}
			}
		} else {
			if(b > 0) {
				b--;
			} else {
				ans += 2;
			}
		}
	}
	
	cout << ans;
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