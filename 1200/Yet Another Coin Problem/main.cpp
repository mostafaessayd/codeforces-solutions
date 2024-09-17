/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1934/problem/B
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
	int n;
	cin >> n;
	
	int ans = 1e9;
	for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			for(int k = 0 ; k < 10 ; k++) {
				for(int l = 0 ; l < 10 ; l++) {
					int rem = n - (i + 3 * j + 6 * k + 10 * l);
					if(rem >= 0 && rem % 15 == 0) {
						ans = min(ans , rem / 15 + i + j + k + l);
					}
	            }
	        }
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