/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/2021/problem/B
rating : 1200
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
	int n , x;
	cin >> n >> x;
	vector<int> vec(n);
	vector<int> freq(n + 1 , 0);
	for(int i = 0 ; i < n ; i++) {
		cin >> vec[i];
		if(vec[i] < n) {
			freq[vec[i]]++;
		}
	}
	
	for(int i = 0 ; i <= n ; i++) {
		if(freq[i] == 0) {
			cout << i << '\n';
			return;
		}
		if(freq[i] > 1 && i + x <= n) {
			freq[i + x] += freq[i] - 1;
		}
	}
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