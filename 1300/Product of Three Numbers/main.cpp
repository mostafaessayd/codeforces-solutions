/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1294/problem/C
 rating : 1300
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
	cin >> n;
	vector<int> div;
	for(int i = 2 ; i <= sqrt(n) ; i++) {
		if(n % i == 0) {
			div.push_back(i);
			if(i != n / i) {
			  div.push_back(n / i);
			}
		}
	}
	
	for(int i = 0 ; i < div.size() ; i++) {
		for(int j = 0 ; j < div.size() ; j++) {
			for(int k = 0 ; k < div.size() ; k++) {
				if(div[i] != div[j] && div[i] != div[k] && div[j] != div[k]) {
					if(div[i] * div[j] * div[k] == n) {
						cout << "YES\n";
						cout << div[i] << ' ' << div[j] << ' ' << div[k] << '\n';
						return;
					}
				}
			}
		}
	}
	
	cout << "NO\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}