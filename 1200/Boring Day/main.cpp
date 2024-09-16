/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1982/problem/C
rating : 1200
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
	int n , l , r;
	cin >> n >> l >> r;
	vector<ll> vec(n);
	for(ll& val : vec) {
		cin >> val;
	}
	
	int ans = 0;
	for(int i = 0 ; i < n ; ) {
		int j = i;
		ll sum = 0;
		while(j < n) {
			sum += vec[j];
			if(sum > r) {
				while(sum > r) {
					sum -= vec[i++];
				}
				break;
			}
			if(sum >= l && sum <= r) {
				ans++;
				i = j + 1;
				break;
			}
			j++;
		}
		
	  if(j == n) {
	  	break;
	  }
	}
	
	cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}